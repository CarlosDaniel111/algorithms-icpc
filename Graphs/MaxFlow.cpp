const long long INF = 1e18;
using edge = tuple<int, ll, ll>;
class max_flow {
   private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<pi> p;

    bool BFS(int s, int t) {  // encontrar aumento de camino
        d.assign(V, -1);
        d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1});  // guardar arbol sp de BFS
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) break;                         // parar al llegar a t
            for (auto &idx : AL[u]) {                  // explorar vecinos de u
                auto &[v, cap, flow] = EL[idx];        // almacenado en EL[idx]
                if ((cap - flow > 0) && (d[v] == -1))  // arista residual positiva
                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx};
            }
        }
        return d[t] != -1;  // tiene aumento de camino
    }

    ll send_one_flow(int s, int t, ll f = INF) {  // enviar un flujo de s->t
        if (s == t) return f;                     // cuello de botella f
        auto &[u, idx] = p[t];
        auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap - flow));
        flow += pushed;
        auto &rflow = get<2>(EL[idx ^ 1]);  // arista atras
        rflow -= pushed;                    // flujo atras
        return pushed;
    }

    ll DFS(int u, int t, ll f = INF) {  // recorrer de s->t
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int)AL[u].size(); ++i) {  // desde ultima arista
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1) continue;  // no esta en el grafo de capas
            if (ll pushed = DFS(v, t, min(f, cap - flow))) {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i] ^ 1]);  // arista atras
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

   public:
    max_flow(int initialV) : V(initialV) {
        EL.clear();
        AL.assign(V, vi());
    }

    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return;                       // para evitar bucles infinito
        EL.emplace_back(v, w, 0);                 // u->v, capacidad w, flujo 0
        AL[u].push_back(EL.size() - 1);           // guardar este indice
        EL.emplace_back(u, directed ? 0 : w, 0);  // arista atras
        AL[v].push_back(EL.size() - 1);           // guardar este indice
    }

    ll edmonds_karp(int s, int t) {
        ll mf = 0;
        while (BFS(s, t)) {              // algoritmo en O(V*E^2)
            ll f = send_one_flow(s, t);  // encontrar y enviar 1 flujo f
            if (f == 0) break;           // si f == 0, parar
            mf += f;                     // si f > 0, sumar a mf
        }
        return mf;
    }

    ll dinic(int s, int t) {
        ll mf = 0;
        while (BFS(s, t)) {           // algoritmo en O(V^2*E)
            last.assign(V, 0);        // aceleracion importante
            while (ll f = DFS(s, t))  // consumir flujo de bloqueo
                mf += f;
        }
        return mf;
    }
};
