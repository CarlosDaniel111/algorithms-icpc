class LazySegmentTree {
  private:
    int n;
    vi A, st, lazy;

    int l(int p) { return (p << 1) + 1; }       // ir al hijo izquierdo
    int r(int p) { return (p << 1) + 2; } // ir al hijo derecho

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

    void update(int index, int start, int end, int i, int j, int val) {
        propagate(index, start, end);
        if ((end < i) || (start > j))
            return;

        if (start >= i && end <= j) {
            st[index] += (end - start + 1) * val;
            if (start != end) {
                lazy[l(index)] += val;
                lazy[r(index)] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
      
        update(l(index), start, mid, i, j, val);
        update(r(index), mid + 1, end, i, j, val);

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
    LazySegmentTree(int sz) : n(sz), st(4 * n), lazy(4 * n) {} // Constructor de st sin valores

    LazySegmentTree(const vi &initialA) : LazySegmentTree((int)initialA.size()) { // Constructor de st con arreglo inicial
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(0, 0, n - 1, i, j, val); }

    int query(int i, int j) { return query(0, 0, n - 1, i, j); }
};
