const double EPS = 1e-9;
double DEG_to_RAD(double d) { return d * M_PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

// Duplicar P[0] al final del vector de puntos
double perimeter(const vector<Point>& P) {
  double ans = 0.0;
  for (int i = 0; i < (int)P.size() - 1; ++i)
    ans += dist(P[i], P[i + 1]);
  return ans;
}

// Formula de Heron
double triangleArea(Point& p1, Point& p2, Point& p3) {
  double a = abs(p2 - p1), b = abs(p3 - p1), c = abs(p3 - p2), s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Con la magnitud del producto cruz
double triangleArea(Point& p1, Point& p2, Point& p3) {
  return cross(p2 - p1, p3 - p1) / 2;
}

double area(const vector<Point>& P) {
  double ans = 0.0;
  for (int i = 0; i < (int)P.size() - 1; ++i)
    ans += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
  return fabs(ans) / 2.0;
}

bool isConvex(const vector<Point>& P) {
  int n = (int)P.size();
  if (n <= 3) return false;
  bool firstTurn = ccw(P[0], P[1], P[2]);
  for (int i = 1; i < n - 1; ++i)
    if (ccw(P[i], P[i + 1], P[(i + 2) == n ? 1 : i + 2]) != firstTurn)
      return false;
  return true;
}

// Retorna 1/0/-1 si el punto p esta dentro/sobre/fuera de
// cualquier poligono P concavo/convexo
int insidePolygon(Point pt, const vector<Point>& P) {
  int n = (int)P.size();
  if (n <= 3) return -1;
  bool on_polygon = false;
  for (int i = 0; i < n - 1; ++i)
    if (fabs(dist(P[i], pt) + dist(pt, P[i + 1]) - dist(P[i], P[i + 1])) < EPS)
      on_polygon = true;
  if (on_polygon) return 0;
  double sum = 0.0;
  for (int i = 0; i < n - 1; ++i) {
    if (ccw(pt, P[i], P[i + 1]))
      sum += angle(P[i], pt, P[i + 1]);
    else
      sum -= angle(P[i], pt, P[i + 1]);
  }
  return fabs(sum) > M_PI ? 1 : -1;
}

// Retorna si el punto esta dentro del triangulo
bool pointInTriangle(Point a, Point b, Point c, Point p) {
  T s1 = abs(cross(a, b, c));
  T s2 = abs(cross(p, a, b)) + abs(cross(p, b, c)) + abs(cross(p, c, a));
  return s1 == s2;
}

// Checa si un punto se encuentra dentro de un poligono convexo
// Nota: el poligono debe estar ordenado contra la manecilla del
// reloj (ccw)
// Necesario: cross(pt1,pt2), sgn(T), sq(pt), pointInTriangle()
// Tiempo: O(log n)
vector<Point> seq;
Point translation;
int n;

void prepare(vector<Point>& points) {
  n = SZ(points);
  int pos = 0;
  FOR(i, 1, n) {
    if (points[i] < points[pos])
      pos = i;
  }
  rotate(points.begin(), points.begin() + pos, points.end());
  n--;
  seq.resize(n);
  FOR(i, 0, n) {
    seq[i] = points[i + 1] - points[0];
  }
  translation = points[0];
}

bool pointInConvexPolygon(Point point) {
  point = point - translation;
  if (cross(seq[0], point) != 0 &&
      sgn(cross(seq[0], point)) != sgn(cross(seq[0], seq[n - 1])))
    return false;
  if (cross(seq[n - 1], point) != 0 &&
      sgn(cross(seq[n - 1], point)) != sgn(cross(seq[n - 1], seq[0])))
    return false;

  if (cross(seq[0], point) == 0)
    return sq(seq[0]) >= sq(point);

  int l = 0, r = n - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int pos = mid;
    if (cross(seq[pos], point) == 0)
      l = mid;
    else
      r = mid;
  }
  int pos = l;
  return isInside(seq[pos], seq[pos + 1], Point{0, 0}, point);
}