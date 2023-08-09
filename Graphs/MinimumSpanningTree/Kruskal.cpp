#include<../Data Structure/DSU.h>

using Edge = tuple<int, int, int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    DSU UF;
    UF.init(V);
    Edge edges[E];

    F0R(i, E) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(edges, edges + E);

    int totalWeight = 0;
    for (int i = 0; i < E && V > 1; i++) {
        auto [w, u, v] = edges[i];  // desempaquetamiento de arista
        if (!UF.sameSet(u, v)) {    // Si no estan en el mismo conjunto, la tomamos
            totalWeight += w;
            V -= UF.unite(u, v);
        }
    }
    cout << "MST weight: " << totalWeight << '\n';
    return 0;
}
