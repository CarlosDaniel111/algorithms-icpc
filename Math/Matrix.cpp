template <typename T>
struct Matrix {
    using VVT = vector<vector<T>>;

    VVT M;
    int n, m;

    Matrix(VVT aux) : M(aux), n(M.size()), m(M[0].size()) {}

    // O(n^3)
    Matrix operator*(Matrix& other) const {
        int k = other.M[0].size();
        VVT C(n, vector<T>(k, 0));
        FOR(i, 0, n)
        FOR(j, 0, k)
        FOR(l, 0, m)
        C[i][j] = (C[i][j] + M[i][l] * other.M[l][j] % MOD) % MOD;
        return Matrix(C);
    }

    // O(n^3 * log p)
    Matrix operator^(ll p) const {
        assert(p >= 0);
        Matrix ret(VVT(n, vector<T>(n))), B(*this);
        FOR(i, 0, n)
        ret.M[i][i] = 1;

        while (p) {
            if (p & 1)
                ret = ret * B;
            p >>= 1;
            B = B * B;
        }
        return ret;
    }
};

// Ejemplo de uso calculando el n-esimo fibonacci
// Para una mayor velocidad realizarlo con 4 variables
Matrix<ll> fibMat({{1, 1}, {1, 0}});
ll fibonacci(ll n) { return (n <= 2) ? (n != 0) : (fibMat ^ n).M[1][0]; }
