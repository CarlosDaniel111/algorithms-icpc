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
  if (SZ(a) == 1)
    return a;

  sort(ALL(a));
  Point p1 = a[0], p2 = a.back();
  vector<Point> up, down;
  up.pb(p1);
  down.pb(p1);
  for (int i = 1; i < (int)SZ(a); i++) {
    if (i == SZ(a) - 1 || cw(p1, a[i], p2, include_collinear)) {
      while (SZ(up) >= 2 && !cw(up[SZ(up) - 2], up[SZ(up) - 1], a[i], include_collinear))
        up.pop_back();
      up.pb(a[i]);
    }
    if (i == SZ(a) - 1 || ccw(p1, a[i], p2, include_collinear)) {
      while (SZ(down) >= 2 && !ccw(down[SZ(down) - 2], down[SZ(down) - 1], a[i], include_collinear))
        down.pop_back();
      down.pb(a[i]);
    }
  }

  if (include_collinear && SZ(up) == SZ(a)) {
    reverse(ALL(a));
    return a;
  }
  vector<Point> ans;
  for (int i = 0; i < (int)SZ(up); i++)
    ans.pb(up[i]);
  for (int i = SZ(down) - 2; i > 0; i--)
    ans.pb(down[i]);

  return ans;
}