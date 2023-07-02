// La Sparse Table es una estructura de datos que nos permite realizar queries
// sobre un arreglo estatico A en O(1), con una construccion en O(n logn) 
// ST[k][i] almacena el {op} en el rango [i, i + 2^k - 1] de A

template <typename T> 
struct SparseTable {
    vector<vector<T>> ST;

    // Cualquier operacion conmutativa
    T op(T &a, T &b) {
        return min(a, b);
    }

    void build(vector<T> &A) {
        ST.assign(30, vector<T>(SZ(A), 0));

        for (int i = 0; i < SZ(A); i++)
            ST[0][i] = A[i];
        
        for (int k = 1; k < 30; k++)
            for (int i = 0; i + (1 << k) <= SZ(A); i++) 
                ST[k][i] = op(ST[k - 1][i], ST[k - 1][i + (1 << (k - 1))]);
    }

    T query(int l, int r) {
        int p = 31 - __builtin_clz(r - l);
        return op(ST[p][l], ST[p][r - (1 << p) + 1]);
    }
};
