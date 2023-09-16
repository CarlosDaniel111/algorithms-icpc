constexpr double EPS = 1e-9;  // 1e-9 es suficiente para problemas de precision doble
constexpr double PI = acos(-1.0);

inline double DEG_to_RAD(double d) { return (d * PI / 180.0); }
inline double RAD_to_DEG(double r) { return (r * 180.0 / PI); }

typedef double T;
struct Point {
  T x, y;

  // Operaciones Punto - Punto
  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  Point operator*(Point b) const { return {x * b.x - y * b.y, x * b.y + y * b.x}; }

  // Operaciones Punto - Numero
  Point operator*(T d) const { return {x * d, y * d}; }
  Point operator/(T d) const { return {x / d, y / d}; }  // Solo para punto flotante

  // Operaciones de comparacion para punto flotante
  bool operator<(Point other) const {
    if (fabs(x - other.x) > EPS)
      return x < other.x;
    return y < other.y;
  }
  bool operator==(Point other) const { return fabs(x - other.x) <= EPS && fabs(y - other.y) <= EPS; }
  bool operator!=(Point other) const { return !(*this == other); }

  // Operaciones de comparacion para enteros
  bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }
};

T sq(Point p) { return p.x * p.x + p.y * p.y; }
double abs(Point p) { return sqrt(sq(p)); }

// Para poder hacer cout << miPunto
ostream& operator<<(ostream& os, Point p) { return os << "(" << p.x << "," << p.y << ")"; }

// Ejemplos de uso
Point a{3, 4}, b{2, -1};
cout << a + b << " " << a - b << "\n";   // (5,3) (1,5)
cout << a * -1 << " " << b / 2 << "\n";  // (-3,-4) (1.5,2)

// Operaciones generales:
Point translate(Point v, Point p) { return p + v; }
Point scale(Point c, double factor, Point p) { return c + (p - c) * factor; }
// Si se desea rotar a partir de un punto C, restar p-c realizar el rotate y sumar p+c
Point rotate(Point p, double a) { return {p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a)}; }
Point perpendicular(Point p) { return {-p.y, p.x}; }
double dist(Point p1, Point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

// Vector desplazamiento desde el punto p1 a p2
Point toVector(Point& p1, Point& p2) { return p2 - p1; }
// Operaciones vectoriales, en donde nuestro punto indica el fin del vector, siendo el origen su inicio
T dot(Point v, Point w) { return v.x * w.x + v.y * w.y; }
bool isPerp(Point v, Point w) { return dot(v, w) == 0; }
Point scale(const Point& v, double s) { return vec(v.x * s, v.y * s); }

// Para c++17
double angle(Point v, Point w) { return acos(clamp(dot(v, w) / abs(v) / abs(w), -1.0, 1.0)); }
// C++14 o menor
double angle(Point v, Point w) {
  double cosTheta = dot(v, w) / abs(v) / abs(w);
  return acos(max(-1.0, min(1.0, cosTheta)));
}

T cross(Point v, Point w) { return v.x * w.y - v.y * w.x; }
T orient(Point a, Point b, Point c) { return cross(b - a, c - a); }

// Funcion signum: -1 si x es negativo, 0 si x = 0 y 1 si x es positivo
template <typename T>
int sgn(T x) {
  return (T(0) < x) - (x < T(0));
}

int manhattan(Point& p1, Point& p2) { return abs(p1.x - p2.x) + abs(p1.y - p2.y); }

bool areCollinear(Point& p, Point& q, Point& r) {
  return abs(cross(toVector(p, q), toVector(p, r))) <= EPS;
}
