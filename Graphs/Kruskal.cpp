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

// DSU
int p[MAXN], rankk[MAXN];
int numSets;

int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSame(int i, int j) { return findSet(i) == findSet(j); }

void unite(int i, int j) {
    if (isSame(i, j))
        return;
    int x = findSet(i), y = findSet(j);
    if (rankk[x] > rankk[y])
        swap(x, y);
    p[x] = y;
    if (rankk[x] == rankk[y])
        ++rankk[y];
    --numSets;
}

typedef tuple<int, int, int> Edge;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    // Inicializando arreglos.
    iota(p, p + V, 0);
    numSets = V;

    Edge edges[V];
    FOR(i, E) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(edges, edges + E);

    int totalWeight = 0;
    for (int i = 0; i < E && numSets > 1; i++) {
        auto [w, u, v] = edges[i]; // desempaquetamiento de arista
        if (!isSame(u, v)) {       // Si no estan en el mismo conjunto, la tomamos
            totalWeight += w;
            unite(u, v);
        }
    }
    cout << "MST weight: " << totalWeight << '\n';
    return 0;
}