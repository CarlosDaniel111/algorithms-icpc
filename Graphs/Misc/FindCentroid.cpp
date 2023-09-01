/**
 * Descripcion: dado un arbol, encuentra su centroide
 * Tiempo: O(V)
 */
int dfs(int u, int p) {
  for (auto v : tree[u])
    if (v != p)
      subtreeSZ[u] += dfs(v, u);
  return subtreeSZ[u] += 1;
}

int centroid(int u, int p) {
  for (auto v : tree[u])
    if (v != p && subtreeSZ[v] * 2 > n)
      return centroid(v, u);
  return u;
}
