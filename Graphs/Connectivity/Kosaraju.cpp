/**
 * Descripcion: sirve para la busqueda de componentes fuertemente conexos (SCC),
 * este realiza dos pasadas DFS, la primera para almacenar el orden de finalizacion
 * decreciente (orden topologico) y la segunda se realiza en un grafo transpuesto a
 * partir del orden topologico para hallar los SCC.
 * Tiempo: O(V + E)
 */

vector<vi> g, gT;
vi dfs_num, S;
int numSCC;

void go(int u, int pass) {
  dfs_num[u] = 1;
  vi &neighbor = (pass == 1) ? g[u] : gT[u];
  for (auto v : neighbor) if (dfs_num[v] == -1) go(v, pass);
  S.pb(u);
}

int korasaju() {
  S.clear();
  dfs_num.assign(SZ(g), -1);
  FOR (u, 0, SZ(g)) if (dfs_num[u] == -1) go(u, 1);
  dfs_num.assign(SZ(g), -1);
  numSCC = 0;
  FOR (i, 0, SZ(g)) if (dfs_num[S[i]] == -1) {
    ++numSCC;
    go(S[i], 2);
  }
  return numSCC;
}
