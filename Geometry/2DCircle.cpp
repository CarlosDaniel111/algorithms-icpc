double DEG_to_RAD(double d) { return d * M_PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }
double PI = 2 * arccos(0.0);
/*
To check if a Point is inside, outside, or exactly on the border of a circle, we can use
the following function. Modify this function a bit for the floating Point version
*/
int insideCircle(const Point_i &p, const Point_i &c, int r) {
  int dx = p.x - c.x, dy = p.y - c.y;
  int Euc = dx * dx + dy * dy, rSq = r * r;      // all integer
  return Euc < rSq ? 1 : (Euc == rSq ? 0 : -1);  // in/border/out
}
/*
Given 2 Points on the circle (p1 and p2) and radius r of the corresponding circle, we
can determine the location of the centers (c1 and c2) of the two possible circles.
*/
bool circle2PtsRad(Point p1, Point p2, double r, Point &c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if (det < EPS) return false;
  double h = sqrt(det);
  // to get the other center, reverse p1 and p2
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true;
}

void circle_line_intersection(double r, Line linea) {
  double a = linea.a, b = linea.b, c = linea.c;
  double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
  if (c * c > r * r * (a * a + b * b) + EPS)
    puts("no points");
  else if (abs(c * c - r * r * (a * a + b * b)) < EPS) {
    puts("1 point");
    cout << x0 << ' ' << y0 << ENDL;
  } else {
    double d = r * r - c * c / (a * a + b * b);
    double mult = sqrt(d / (a * a + b * b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    puts("2 points");
    cout << ax << ' ' << ay << ENDL
         << bx << ' ' << by << ENDL;
  }
}
