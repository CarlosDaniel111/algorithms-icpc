/*Grafo de ejemplo:
  5 7
  0 1 4
  0 2 4
  0 3 6
  0 4 6
  1 2 2
  2 3 8
  3 4 9
  Salida esperada: 18
*/

#define eb emplace_back;

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

const int MAXN = 1e5 + 5;

vii graph[MAXN];
bool taken[MAXN];  // Inicialmente en false todos
pqg<ii> pq;        // Para ir seleccionando las aristas de menor peso

void process(int u) {
    taken[u] = 1;
    for (auto &[v, w] : graph[u])
        if (!taken[v])
            pq.emplace(w, v);
}

int main() {
    int V, E;
    cin >> V >> E;
    FOR(i, E) {
        int u, v, w;
        cin >> u >> v >> w;
        // u--; v--;
        graph[u].eb(v, w);
        graph[v].eb(u, w);
    }

    process(0);                                   // take+process vertex 0
    int totalWeight = 0, takenEdges = 0;          // no edge has been taken
    while (!pq.empty() && takenEdges != V - 1) {  // up to O(E)
        auto [w, u] = pq.top();                   // Se desempaqueta la arista con menor peso
        pq.pop();

        if (taken[u]) continue;  // Si ha sido tomada

        totalWeight += w;
        process(u);
        ++takenEdges;
    }
    cout << "MST weight: " << totalWeight << '\n';
    return 0;
}
