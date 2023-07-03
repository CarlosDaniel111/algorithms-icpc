// Time complexity O(V^2 * E^2)

const ll INF = 1e18;
typedef tuple<int, ll, ll, ll> edge;

class min_cost_max_flow {
   private:
    int V;
    ll total_cost;
    vector<edge> EL;
    vector<vi> AL;
    vll d;
    vi last, vis;

    bool SPFA(int s, int t) {  // SPFA para encontrar un augmenting path en el grafo residual
        d.assign(V, INF);
        d[s] = 0;
        vis[s] = 1;
        queue<int> q({s});
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (auto &idx : AL[u]) {                            // Explorar los vecinos de u
                auto &[v, cap, flow, cost] = EL[idx];            // Guardado en EL[idx]
                if ((cap - flow > 0) && (d[v] > d[u] + cost)) {  // Arista residual positiva
                    d[v] = d[u] + cost;
                    if (!vis[v]) q.push(v), vis[v] = 1;
                }
            }
        }
        return d[t] != INF;  // Tiene un augmenting path
    }

    ll DFS(int u, int t, ll f = INF) {  // Ir de s->t
        if ((u == t) || (f == 0)) return f;
        vis[u] = 1;
        for (int &i = last[u]; i < (int)AL[u].size(); ++i) {  // Desde la ultima arista
            auto &[v, cap, flow, cost] = EL[AL[u][i]];
            if (!vis[v] && d[v] == d[u] + cost) {  // En el grafo del nivel actual
                if (ll pushed = DFS(v, t, min(f, cap - flow))) {
                    total_cost += pushed * cost;
                    flow += pushed;
                    auto &[rv, rcap, rflow, rcost] = EL[AL[u][i] ^ 1];  // Arista de regreso
                    rflow -= pushed;
                    vis[u] = 0;
                    return pushed;
                }
            }
        }
        vis[u] = 0;
        return 0;
    }

   public:
    min_cost_max_flow(int initialV) : V(initialV), total_cost(0) {
        EL.clear();
        AL.assign(V, vi());
        vis.assign(V, 0);
    }

    // Si se añade una arista bidireccional u<->v con peso w en el grafo de flujo,
    // asigna directed = false. El valor por defecto es true (Arista dirigida)
    void add_edge(int u, int v, ll w, ll c, bool directed = true) {
        if (u == v) return;                         // Por seguridad: Evita ciclos en el mismo nodo
        EL.emplace_back(v, w, 0, c);                // u->v, cap w, flow 0, cost c
        AL[u].push_back(EL.size() - 1);             // Para recordar el indice
        EL.emplace_back(u, 0, 0, -c);               // Arista de regreso
        AL[v].push_back(EL.size() - 1);             // Para recordar el indice
        if (!directed) add_edge(v, u, w, c, true);  // Añadir de nuevo en reversa
    }

    pair<ll, ll> mcmf(int s, int t) {
        ll mf = 0;                    // mf = Max flow
        while (SPFA(s, t)) {          // Time complexity O(V^2*E)
            last.assign(V, 0);        // Aceleración importante
            while (ll f = DFS(s, t))  // exhaust blocking flow
                mf += f;
        }
        return {mf, total_cost};
    }
};