/* Implementado para RSQ, pero es posible usar cualquier operacion conmutativa
   (no importa el orden) como la multiplicacion, XOR, OR, AND, MIN, MAX, etc. */

class SegmentTree {
   private:
    int n;
    vi arr, st;

    int l(int p) { return (p << 1) + 1; }  // Ir al hijo izquierdo
    int r(int p) { return (p << 1) + 2; }  // Ir al hijo derecho

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

    int query(int index, int start, int end, int i, int j) {
        if (j < start || end < i)
            return 0;  // Si ese rango no nos sirve, retornar un valor que no cambie nada

        if (i <= start && end <= j)
            return st[index];

        int mid = (start + end) / 2;

        return query(l(index), start, mid, i, j) + query(r(index), mid + 1, end, i, j);
    }

    void update(int index, int start, int end, int idx, int val) {
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
    SegmentTree(int sz) : n(sz), st(4 * n) {}  // Constructor de st sin valores

    SegmentTree(const vi &initialArr) : SegmentTree((int)initialArr.size()) {  // Constructor de st con arreglo inicial
        arr = initialArr;
        build(0, 0, n - 1);
    }

    void update(int i, int val) { update(0, 0, n - 1, i, val); }

    int query(int i, int j) { return query(0, 0, n - 1, i, j); }
};
