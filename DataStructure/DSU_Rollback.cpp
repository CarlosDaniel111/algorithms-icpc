/**
 * Descripcion: Estructura de conjuntos disjuntos con la 
 * capacidad de regresar a estados anteriores.
 * Si no es necesario, ignorar st, time() y rollback().
 * Uso: int t = uf.time(); ...; uf.rollback(t)
 * Tiempo: O(log n)
 */

struct RollbackDSU {
    vector<int> e;
    vector<pair<int, int>> st;
    RollbackDS(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return st.size(); }
    void rollback(int t) {
        for (int i = time(); i-- > t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) 
            return false;
        if (e[a] > e[b]) 
            swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};
