#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e5 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

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

vii graph[MAXN];
bool taken[MAXN]; //Inicialmente en false todos
priority_queue<ii, vii, greater<ii>> pq; //Para ir seleccionando las aristas de menor peso

void process(int u) {
    taken[u] = 1;
    for (auto &[v, w] : graph[u])
        if (!taken[v])
            pq.emplace(w, v);
}

int main() {
    int V, E; cin >> V >> E;
    FOR(i, E){
        int u, v, w;
        cin >> u >> v >> w;
        //u--; v--;
        graph[u].eb(v, w); graph[v].eb(u, w);
    }

    process(0);                                    // take+process vertex 0
    int totalWeight = 0, takenEdges = 0;               // no edge has been taken
    while (!pq.empty() && takenEdges != V - 1) {                          // up to O(E)
        auto [w, u] = pq.top(); //Se desempaqueta la arista con menor peso
        pq.pop();

        if (taken[u]) continue; //Si ha sido tomada

        totalWeight += w;
        process(u);
        ++takenEdges;
    }
    cout << "MST weight: " << totalWeight << '\n';
    return 0;
}
