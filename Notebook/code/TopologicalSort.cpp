const int MAXN = 1e5 + 5;
int n, m;                     // Numero de nodos y aristas
vi graph[MAXN];               // Grafo
vi sorted_nodes;              // Arreglo de nodos ordenados topologicamente
bool visited[MAXN] = {false}; // Arreglo de visitados
stack<int> s;

// Funcion DFS para recorrer el grafo en profundidad
void dfs(int u) {
    visited[u] = true;
    for (auto v : graph[u]) {
        if (!visited[v])
            dfs(v);
    }
    s.push(u);
}

void topo_sort() {
    // Recorrido DFS para marcar los nodos visitados y llenar la pila
    FOR(i, n) {
        if (!visited[i])
            dfs(i);
    }

    // Llenado del arreglo
    while (!s.empty()) {
        sorted_nodes.push_back(s.top());
        s.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    FOR(i, m) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    topo_sort();
    if (sorted_nodes.size() < n) {
        cout << "El grafo tiene un ciclo" << ENDL;
    } else {
        cout << "Orden topologico: ";
        for (int u : sorted_nodes) {
            cout << u << " ";
        }
    }
    return 0;
}
