/**
 * Descripcion: algoritmo para buscar puentes en un grafo
 * Tiempo: O(V + E)
 */

vector<vi> g;
vector<bool> articulation;
vi tin, low;
int timer, dfsRoot, rootChildren;

void dfs(int u, int p = -1) {
  tin[u] = low[u] = timer++;
  for (int v : g[u]) {
    if (v == p) continue;
    if (tin[v] != -1) low[u] = min(low[u], tin[v]);
    else {
      if (u == dfsRoot) ++rootChildren;  // La raiz es un punto de articulacion
        
      dfs(v, u);

      if (low[v] >= tin[u]) articulation[u] = 1;
      if (low[v] > tin[u]) ES_PUENTE(u, v);
      
      low[u] = min(low[u], low[v]);
    }
  }
}

void find_bridges_articulations() {
  tin.assign(SZ(g), -1);
  low.assign(SZ(g), -1);
  timer = 0;

  for (int i = 0; i < SZ(g); ++i) {
    if (tin[i] == -1) {
      dfsRoot = i;
      rootChildren = 0;
      dfs(i);
      articulation[dfsRoot] = (rootChildren > 1);
    }
  }
}
