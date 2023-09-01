/**
 * Descripcion: arbol de segmentos, bastante poderoso para
 * realizar consultas de min/max en un rango y actualizaciones
 * en un rango de manera eficiente.
 * Uso: LazyRMQ ST(arr)
 * Tiempo: O(log n)
 */

class LazyRMQ {
 private:
  int n;
  vi A, st, lazy;

  int l(int p) { return (p << 1) + 1; }
  int r(int p) { return (p << 1) + 2; }

  int conquer(int a, int b) {
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
      else
        A[L] = lazy[p];
      lazy[p] = -1;
    }
  }

  int query(int p, int L, int R, int i, int j) {
    propagate(p, L, R);
    if (i > j)
      return -1;
    if ((L >= i) && (R <= j))
      return st[p];
    int m = (L + R) / 2;
    return conquer(query(l(p), L, m, i, min(m, j)),
                   query(r(p), m + 1, R, max(i, m + 1), j));
  }

  void update(int p, int L, int R, int i, int j, int val) {
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
      int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
      int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
      st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
    }
  }

 public:
  LazyRMQ(int sz) : n(sz), st(4 * n), lazy(4 * n, -1) {}

  LazyRMQ(const vi &initialA) : LazyRMQ((int)initialA.size()) {
    A = initialA;
    build(1, 0, n - 1);
  }

  void update(int i, int j, int val) { update(0, 0, n - 1, i, j, val); }  // [i, j]
  int query(int i, int j) { return query(0, 0, n - 1, i, j); }            // [i, j]
};
