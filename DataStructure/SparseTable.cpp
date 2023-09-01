/**
 * Descripcion: nos permite realizar eficientemente consultas
 * en rango del minimo o maximo elemento, cuando no se actualiza
 * nunca el arreglo, ST[k][i] = min/max(A[i]...A[i + 2^k - 1]);
 * Tiempo: O(n log n) en construccion y O(1) por query
 */

template <typename T>
struct SparseTable {
  vector<vector<T>> ST;

  void build(vector<T> &A) {
    const int MAX_LOG = __builtin_clz(A.size()) + 2;
    ST.assign(MAX_LOG, vector<T>(SZ(A), 0));

    for (int i = 0; i < SZ(A); i++)
      ST[0][i] = A[i];

    for (int k = 1; k < MAX_LOG; k++)
      for (int i = 0; i + (1 << k) <= SZ(A); i++)
        ST[k][i] = min(ST[k - 1][i], ST[k - 1][i + (1 << (k - 1))]);
  }

  T query(int l, int r) {  // [l, r]
    int p = 31 - __builtin_clz(r - l);
    return min(ST[p][l], ST[p][r - (1 << p) + 1]);
  }
};
