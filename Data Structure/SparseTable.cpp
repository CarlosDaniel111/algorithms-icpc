// Nos permite realizar RMQ sobre un arreglo estatico A en O(1)
// con una construccion en O(n log n) ST[k][i] almacena RMQ(i, i + 2^k - 1)

template <typename T> 
struct SparseTable {
    vector<vector<T>> ST;

    void build(vector<T> &A) {
        ST.assign(30, vector<T>(SZ(A), 0));

        for (int i = 0; i < SZ(A); i++)
            ST[0][i] = A[i];
        
        for (int k = 1; k < 30; k++)
            for (int i = 0; i + (1 << k) <= SZ(A); i++) 
                ST[k][i] = min(ST[k - 1][i], ST[k - 1][i + (1 << (k - 1))]);
    }

    T query(int l, int r) {
        int p = 31 - __builtin_clz(r - l);
        return min(ST[p][l], ST[p][r - (1 << p) + 1]);
    }
};
