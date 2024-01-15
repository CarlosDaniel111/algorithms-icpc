/**
 * Descripcion: tiene como principal funcion calcular la suma del
 * peso de las aristas del arbol minimo de expansion (MST) de un grafo,
 * la estrategia es ir construyendo gradualmente el MST, se selecciona un
 * nodo arbitrario y se agregan sus aristas con nodos que no hayan
 * sido agregados con anterioridad y se va tomando la de menor peso hasta
 * completar el MST.
 * Tiempo: O(E log E)
 */

int V, E;
vector<vector<pi>> graph;
vector<bool> taken;
priority_queue<pi> pq;

void process(int u) {
  taken[u] = 1;
  for (auto &[v, w] : graph[u])
    if (!taken[v])
      pq.push({-w, v});
}

int prim() {
  taken.assign(SZ(graph), 0);
  process(0);
  int totalWeight = 0, takenEdges = 0;
  while (!pq.empty() && takenEdges != V - 1) {
    auto [w, u] = pq.top();
    pq.pop();

    if (taken[u]) continue;

    totalWeight -= w;
    process(u);
    ++takenEdges;
  }
  return totalWeight;
}
