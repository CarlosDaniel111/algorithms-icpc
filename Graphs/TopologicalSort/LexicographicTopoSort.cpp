const int MAXN = 1e5 + 5;
int n, m;            // Numero de nodos y aristas
vi graph[MAXN];      // Grafo
int in_degree[MAXN]; // Grado de entrada de cada nodo
vi sorted_nodes;     // Arreglo de nodos ordenados topologicamente

void topo_sort() {
    priority_queue<int, vector<int>, greater<int>> q;
    FOR(i, n) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        sorted_nodes.push_back(u);
        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                q.push(v);
        }
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
        in_degree[v]++;
    }
    topo_sort();

    if (sorted_nodes.size() < n) {
        cout << "El grafo tiene un ciclo" << ENDL;
    } else {
        cout << "Orden topologico lexicograficamente menor: ";
        for (int u : sorted_nodes) {
            cout << u << " ";
        }
    }

    return 0;
}
