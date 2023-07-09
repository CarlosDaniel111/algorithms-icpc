// Implementado para minimo, es posible cambiar a cualquier operacion conmutativa
template <class T> class SegmentTree {
private:
    const T DEFAULT = 1e18;  // Causa overflow si T es int

    vector<T> ST;
    int len;

public:
    SegmentTree(int len) : len(len), ST(len * 2, DEFAULT) {}
    SegmentTree(vector<T>& v) : SegmentTree(v.size()) {
        for (int i = 0; i < len; i++)
            set(i, v[i]);
    }

    void set(int ind, T val) {
        ind += len;
        ST[ind] = val;
        for (; ind > 1; ind /= 2) {
            ST[ind / 2] = min(ST[ind], ST[ind ^ 1]); // Operacion
        }
    }

    T query(int start, int end) {
        end++;
        T ans = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { ans = min(ans, ST[start++]); } // Operacion
            if (end % 2 == 1) { ans = min(ans, ST[--end]); } // Operacion
        }
        return ans;
    }
};
