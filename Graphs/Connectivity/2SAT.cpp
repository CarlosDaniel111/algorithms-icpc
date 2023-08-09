/*  
    Time complexity O(N + E), donde N es el numero de variables booleanas y E es el numero de clausulas
    Las variables negadas son representadas por inversiones de bits (~x)
    Uso:
        TwoSat ts(numero de variables booleanas);
        ts.either(0, ~3);           La variable 0 es verdadera o la variable 3 es falsa
        ts.setValue(2);             La variable 2 es verdadera
        ts.atMostOne({0, ~1, 2});   <= 1 de vars 0, ~1 y 2 son verdedero
        ts.solve();                 Retorna verdadero si existe solucion
        ts.values[0..N-1]           Tiene los valores asignados a las variables
    Source: KACTL
*/
typedef vector<int> vi;

struct TwoSat {
    int N; vector<vi> adj;
    vi values; // 0 = false, 1 = true

    TwoSat(int n = 0) : N(n), adj(2*n) {}

    int addVar() { adj.emplace_back(); adj.emplace_back(); return N++; }    // Opcional

    // Agrega una disyuncion
    void either(int x, int y) { // Nota: (a v b), es equivalente a la expresion (~a -> b) n (~b -> a)
        x = max(2*x, -1-2*x), y = max(2*y, -1-2*y);
        adj[x].push_back(y^1), adj[y].push_back(x^1);
    }
    void setValue(int x) { either(x, x); }                          // La variable x debe tener el valor indicado
    void implies(int x, int y) { either(~x, y); }                   // La variable x implica a y
    void make_diff(int x, int y) { either(x, y); either(~x, ~y); }  // Los valores tienen que ser diferentes
    void make_eq(int x, int y) {either(~x, y); either(x, ~y); }     // Los valores tienen que ser iguales

    void atMostOne(const vi& li) { // Opcional
        if (li.size() <= 1) return;
        int cur = ~li[0];
        for(int i = 2; i < li.size(); i++){
            int next = addVar();
            either(cur, ~li[i]); either(cur, next);
            either(~li[i], next); cur = ~next;
        }
        either(cur, ~li[1]);
    }

    vi dfs_num, comp; stack<int> st; int time = 0;
    int tarjan(int u) {    // Tarjan para encontrar los SCCs
        int x, low = dfs_num[u] = ++time; st.push(u);
        for(int v : adj[u]) if (!comp[v])
            low = min(low, dfs_num[v] ?: tarjan(v));
        if (low == dfs_num[u]) do {
            x = st.top(); st.pop();
            comp[x] = low;
            if (values[x>>1] == -1)
                values[x>>1] = x&1;
        } while (x != u);
        return dfs_num[u] = low;
    }

    bool solve() {
        values.assign(N, -1), dfs_num.assign(2*N, 0), comp.assign(2*N, 0);
        for(int i = 0; i < 2*N; i++)
            if (!comp[i])
                tarjan(i);
        for(int i = 0; i < N; i++)
            if (comp[2*i] == comp[2*i+1])
                return 0;
        return 1;
    }
};
