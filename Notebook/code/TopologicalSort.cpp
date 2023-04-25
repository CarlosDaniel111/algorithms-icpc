#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ENDL '\n'
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e5 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

int n, m;                     // Numero de nodos y aristas
vi graph[MAXN];               // Grafo
vi sorted_nodes;              // Arreglo de nodos ordenados topologicamente
bool visited[MAXN] = {false}; // Arreglo de visitados
stack<int> s;

// Función DFS para recorrer el grafo en profundidad
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
