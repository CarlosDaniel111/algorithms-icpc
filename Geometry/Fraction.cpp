/**
 * Estructura para manejar fracciones, puede ser util cuando necesitamos una
 * gran precision y no se manejen numeros irracionales
 * Tiempo: O(1) 
 */
struct Frac{
    int a, b;

    Frac() {}
    Frac(int _a, int _b) {
        assert(_b > 0);
        if ((_a < 0 && _b < 0) || (_a > 0 && _b < 0)) {
            _a = -_a;
            _b = -_b;
        }

        int GCD = gcd(abs(_a), abs(_b));

        a = _a / GCD;
        b = _b / GCD;
    }

    Frac operator*(Frac& other) const { return Frac(a * other.a, b * other.b); }
    Frac operator/(Frac& other) const { 
        Frac o(other.b, other.a); 
        return (*this) * o; 
    }
    Frac operator+(Frac& other) const {
        int sup = a * other.b + b * other.a, inf = b * other.b;
        return Frac(sup, inf);
    }
    Frac operator-(Frac& other) const {
        int sup = a * other.b - b * other.a, inf = b * other.b;
        return Frac(sup, inf);
    }
    Frac operator*(int &x) const { return Frac(a * x, b); }
    Frac operator/(int &x) const {
        Frac o(1, x);
        return (*this) * o;
    }
    bool operator<(Frac& other) const { // PROVISIONAL, IMPLEMENTARLA MEJOR SI HACEN FALTA LOWER BOUNDS 
        if (a != other.a)
            return a < other.a;
        return b < other.b;
    }
    bool operator==(Frac& other) const {
        return a == other.a && b == other.b;
    }
    bool operator!=(Frac& other) const {
        return !(*this == other);
    }
};
