/**
 * Descripcion: arbol de segmentos, bastante poderoso para
 * realizar consultas de min/max en un rango y actualizaciones
 * en un rango de manera eficiente.
 * Uso: LazyRMQ ST(arr)
 * Tiempo: O(log n)
 */

template <class T>
class LazyRMQ {
 private:
  int n;
  vector<T> A, st, lazy;

  int l(int p) { return (p << 1) + 1; }
  int r(int p) { return (p << 1) + 2; }

  T conquer(T a, T b) {
    if (a == -1)
      return b;
    if (b == -1)
      return a;
    return min(a, b);
  }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = A[L];
    else {
      int m = (L + R) / 2;
      build(l(p), L, m);
      build(r(p), m + 1, R);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {
      st[p] = lazy[p];
      if (L != R)
        lazy[l(p)] = lazy[r(p)] = lazy[p];
      lazy[p] = -1;
    }
  }

  T query(int p, int L, int R, int i, int j) {
    propagate(p, L, R);
    if (i > j)
      return -1;
    if ((L >= i) && (R <= j))
      return st[p];
    int m = (L + R) / 2;
    return conquer(query(l(p), L, m, i, min(m, j)),
                   query(r(p), m + 1, R, max(i, m + 1), j));
  }

  void update(int p, int L, int R, int i, int j, T val) {
    propagate(p, L, R);
    if (i > j)
      return;
    if ((L >= i) && (R <= j)) {
      lazy[p] = val;
      propagate(p, L, R);
    } else {
      int m = (L + R) / 2;
      update(l(p), L, m, i, min(m, j), val);
      update(r(p), m + 1, R, max(i, m + 1), j, val);
      T lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
      T rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
      st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
    }
  }

 public:
  LazyRMQ(int sz) : n(sz), st(4 * n), lazy(4 * n, -1) {}

  LazyRMQ(const vector<T> &initialA) : LazyRMQ(SZ(initialA)) {
    A = initialA;
    build(0, 0, n - 1);
  }

  void update(int i, int j, T val) { update(0, 0, n - 1, i, j, val); }  // [i, j]
  T query(int i, int j) { return query(0, 0, n - 1, i, j); }            // [i, j]
};
