typedef double T;
struct pt {
    T x, y;
    pt operator+(pt p) { return {x + p.x, y + p.y}; }
    pt operator-(pt p) { return {x - p.x, y - p.y}; }
    pt operator*(T d) { return {x * d, y * d}; }
    pt operator/(T d) { return {x / d, y / d}; }  // only for floatingpoint
};

bool operator==(pt a, pt b) { return a.x == b.x && a.y == b.y; }
bool operator!=(pt a, pt b) { return !(a == b); }

// Para poder hacer cout << miPunto
ostream& operator<<(ostream& os, pt p) { return os << "(" << p.x << "," << p.y << ")"; }

// Ejemplos de uso
pt a{3, 4}, b{2, -1};
cout << a + b << " " << a - b << "\n";   // (5,3) (1,5)
cout << a * -1 << " " << b / 2 << "\n";  // (-3,-4) (1.5,2)

// Operaciones generales:
pt translate(pt v, pt p) { return p + v; }
pt scale(pt c, double factor, pt p) { return c + (p - c) * factor; }
pt rot(pt p, double a) { return {p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a)}; }

// Operaciones vectoriales, en donde nuestro punto indica el fin del vector, siendo el origen su inicio
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }
bool isPerp(pt v, pt w) { return dot(v, w) == 0; }

// Para c++17
double angle(pt v, pt w) { return acos(clamp(dot(v, w) / abs(v) / abs(w), -1.0, 1.0)); }
// C++14 o menor
double angle(pt v, pt w) {
    double cosTheta = dot(v, w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}
