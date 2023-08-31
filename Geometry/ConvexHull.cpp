/**
 * Descripcion: encuentra la envolvente convexa de un conjunto
 * de puntos dados. Una envolvente convexa es la minima region
 * convexa que contiene a todos los puntos del conjunto.
 * Tiempo: O(n log n)
 */

int orientation(Point a, Point b, Point c) {
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1;  // clockwise
    if (v > 0) return +1;  // counter-clockwise
    return 0;
}

bool cw(Point a, Point b, Point c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(Point a, Point b, Point c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

vector<Point> convex_hull(vector<Point>& a, bool include_collinear = false) {
    if (a.size() == 1)
        return a;

    sort(ALL(a));
    Point p1 = a[0], p2 = a.back();
    vector<Point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return a;
    }
    vector<Point> ans;
    for (int i = 0; i < (int)up.size(); i++)
        ans.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        ans.push_back(down[i]);

    return ans;
}