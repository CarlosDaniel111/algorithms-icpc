const int MAXN = 1e6 + 5;

int n;                  // number of nodes
vector<int> adj[MAXN];  // adjacency list of graph
bool articulation[MAXN];
int tin[MAXN], low[MAXN], timer, dfsRoot, rootChildren;

void dfs(int u, int p = -1) {
    tin[u] = low[u] = timer++;
    for (int to : adj[u]) {
        if (to == p)
            continue;
        if (tin[to] != -1)
            low[u] = min(low[u], tin[to]);
        else {
            if (u == dfsRoot)
                ++rootChildren;  // Caso especial si la raiz es un punto de articulacion

            dfs(to, u);

            if (low[to] >= tin[u])  // Busca si es un punto de articulacion
                articulation[u] = 1;
            if (low[to] > tin[u])  // Busca si es un puente
                IS_BRIDGE(u, to);

            low[u] = min(low[u], low[to]);
        }
    }
}

void find_bridges_articulations() {
    timer = 0;
    fill(tin, tin + n, -1);
    fill(low, low + n, -1);

    for (int i = 0; i < n; ++i) {
        if (tin[i] == -1) {
            dfsRoot = i;
            rootChildren = 0;
            dfs(i);
            articulation[dfsRoot] = (rootChildren > 1);
        }
    }
}
