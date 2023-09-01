/**
 * Descripcion: sirve para la busqueda de componentes fuertemente conexos (SCC),
 * este realiza dos pasadas DFS, la primera para almacenar el orden de finalizacion
 * decreciente (orden topologico) y la segunda se realiza en un grafo transpuesto a
 * partir del orden topologico para hallar los SCC.
 * Tiempo: O(V + E)
 */

vi graph[MAXN];    // Grafo
vi graph_T[MAXN];  // Grafo transpuesto
vi dfs_num;
vi S;
int N, numSCC;

void Kosaraju(int u, int pass) {
  dfs_num[u] = 1;
  vi &neighbor = (pass == 1) ? graph[u] : graph_T[u];
  for (auto v : neighbor) {
    if (dfs_num[v] == -1)
      Kosaraju(v, pass);
  }
  S.pb(u);
}

int main() {
  S.clear();
  dfs_num.assign(N, -1);
  F0R(u, N) {
    if (dfs_num[u] == -1)
      Kosaraju(u, 1);
  }
  dfs_num.assign(N, -1);
  numSCC = 0;
  R0F(i, N) {  // Segunda pasada
    if (dfs_num[S[i]] == -1) {
      ++numSCC;
      Kosaraju(S[i], 2);
    }
  }
  cout << numSCC << ENDL;
}
