/**
 * Descripcion: arbol de segmentos, bastante poderoso para
 * realizar consultas de suma en un rango y actualizaciones
 * de suma en un rango de manera eficiente. El metodo add
 * agrega x a todos los numeros en el rango [start, end].
 * Uso: LazySegmentTree ST(arr)
 * Tiempo: O(log n)
 */

class LazySegmentTree {
 private:
  int n;
  vi A, st, lazy;

  inline int l(int p) { return (p << 1) + 1; }  // ir al hijo izquierdo
  inline int r(int p) { return (p << 1) + 2; }  // ir al hijo derecho

  void build(int index, int start, int end) {
    if (start == end) {
      st[index] = A[start];
    } else {
      int mid = (start + end) / 2;
      build(l(index), start, mid);
      build(r(index), mid + 1, end);
      st[index] = st[l(index)] + st[r(index)];
    }
  }

  // Nota: Si se utiliza para el minimo o maximo de un rango no se le agrega el (end - start + 1)
  void propagate(int index, int start, int end) {
    if (lazy[index] != 0) {
      st[index] += (end - start + 1) * lazy[index];
      if (start != end) {
        lazy[l(index)] += lazy[index];
        lazy[r(index)] += lazy[index];
      }
      lazy[index] = 0;
    }
  }

  void add(int index, int start, int end, int i, int j, int x) {
    propagate(index, start, end);
    if ((end < i) || (start > j))
      return;

    if (start >= i && end <= j) {
      st[index] += (end - start + 1) * x;
      if (start != end) {
        lazy[l(index)] += x;
        lazy[r(index)] += x;
      }
      return;
    }
    int mid = (start + end) / 2;

    add(l(index), start, mid, i, j, x);
    add(r(index), mid + 1, end, i, j, x);

    st[index] = (st[l(index)] + st[r(index)]);
  }

  int query(int index, int start, int end, int i, int j) {
    propagate(index, start, end);
    if (end < i || start > j)
      return 0;
    if ((i <= start) && (end <= j))
      return st[index];

    int mid = (start + end) / 2;

    return query(l(index), start, mid, i, j) + query(r(index), mid + 1, end, i, j);
  }

 public:
  LazySegmentTree(int sz) : n(sz), st(4 * n), lazy(4 * n) {}

  LazySegmentTree(const vi &initialA) : LazySegmentTree((int)initialA.size()) {
    A = initialA;
    build(0, 0, n - 1);
  }
  // [i, j]
  void add(int i, int j, int val) { add(0, 0, n - 1, i, j, val); }  // [i, j]
  int query(int i, int j) { return query(0, 0, n - 1, i, j); }      // [i, j]
};
