struct Line {
    double a, b, c;
    bool operator<(Line& other) const {
        if (fabs(a - other.a) >= EPS)
            return a < other.a;
        if (fabs(b - other.b) >= EPS)
            return b < other.b;
        return c < other.c;
    }
};

Line pointsToLine(Point& p1, Point& p2) {
    if (abs(p1.x - p2.x) <= EPS)
        return Line{1.0, 0.0, -p1.x};
    double a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    return Line{a, 1.0, -(double)(a * p1.x) - p1.y};
}

Line pointSlopeToLine(Point& p, double& m) { return Line{-m, 1, -((-m * p.x) + p.y)}; }

bool areParallel(Line& l1, Line& l2) { return (abs(l1.a - l2.a) <= EPS) && (abs(l1.b - l2.b) <= EPS); }

bool areSame(Line& l1, Line& l2) { return areParallel(l1, l2) && (abs(l1.c - l2.c) <= EPS); }

bool areIntersect(Line l1, Line l2, Point& p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
}
