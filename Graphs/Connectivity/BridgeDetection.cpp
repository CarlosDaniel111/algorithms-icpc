/**
 * Descripcion: algoritmo para buscar puentes en un grafo
 * Tiempo: O(V + E)
 */

int n;
vector<int> g[MAXN];
bool articulation[MAXN];
int tin[MAXN], low[MAXN], timer, dfsRoot, rootChildren;

void dfs(int u, int p = -1) {
  tin[u] = low[u] = timer++;
  for (int v : g[u]) {
    if (v == p)
      continue;
    if (tin[v] != -1)
      low[u] = min(low[u], tin[v]);
    else {
      if (u == dfsRoot)  // La raiz es un punto de articulacion
        ++rootChildren;

      dfs(v, u);

      if (low[v] >= tin[u])
        articulation[u] = 1;
      if (low[v] > tin[u])
        // La arista (u, v) es un puente

        low[u] = min(low[u], low[v]);
    }
  }
}

void find_bridges_articulations() {
  memset(tin, tin + n, -1);
  memset(low, low + n, -1);

  for (int i = 0; i < n; ++i) {
    if (tin[i] == -1) {
      dfsRoot = i;
      rootChildren = 0;
      dfs(i);
      articulation[dfsRoot] = (rootChildren > 1);
    }
  }
}
