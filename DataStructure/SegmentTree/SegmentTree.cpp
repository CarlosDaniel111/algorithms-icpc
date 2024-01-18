/**
 * Descripcion: arbol de segmentos, bastante poderoso para
 * realizar consultas de rango y actualizaciones de punto,
 * se puede utilizar cualquier operacion conmutativa, es decir,
 * aquella en donde el orden de evaluacion no importe: suma,
 * multiplicacion, XOR, OR, AND, MIN, MAX, etc.
 * Tiempo: O(n log n) en construccion y O(log n) por consulta
 */

template <typename T>
class SegmentTree {
 private:
  int n;
  vector<T> arr, st;

  int l(int p) { return (p << 1) + 1; }
  int r(int p) { return (p << 1) + 2; }

  void build(int index, int start, int end) {
    if (start == end)
      st[index] = arr[start];
    else {
      int mid = (start + end) / 2;

      build(l(index), start, mid);
      build(r(index), mid + 1, end);

      st[index] = st[l(index)] + st[r(index)];
    }
  }

  T query(int index, int start, int end, int i, int j) {
    if (j < start || end < i)
      return 0;  // Si ese rango no nos sirve, retornar un valor que no cambie nada

    if (i <= start && end <= j)
      return st[index];

    int mid = (start + end) / 2;

    return query(l(index), start, mid, i, j) + query(r(index), mid + 1, end, i, j);
  }

  void update(int index, int start, int end, int idx, T val) {
    if (start == end)
      st[index] = val;
    else {
      int mid = (start + end) / 2;
      if (start <= idx && idx <= mid)
        update(l(index), start, mid, idx, val);
      else
        update(r(index), mid + 1, end, idx, val);

      st[index] = st[l(index)] + st[r(index)];
    }
  }

 public:
  SegmentTree(int sz) : n(sz), st(4 * n) {}

  SegmentTree(const vector<T> &initialArr) : SegmentTree((int)initialArr.size()) {
    arr = initialArr;
    build(0, 0, n - 1);
  }

  void update(int i, T val) { update(0, 0, n - 1, i, val); }

  T query(int i, int j) { return query(0, 0, n - 1, i, j); }  // [i, j]
};
