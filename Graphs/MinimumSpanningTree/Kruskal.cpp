/**
 * Descripcion: tiene como principal funcion calcular la suma del
 * peso de las aristas del arbol minimo de expansion (MST) de un grafo,
 * la estrategia es ir construyendo gradualmente el MST, donde
 * iterativamente se coloca la arista disponible con menor peso y 
 * ademas no conecte 2 nodos que pertenezcan al mismo componente.
 * Tiempo: O(E log E)
 */

#include<../Data Structure/DSU.h>

using Edge = tuple<int, int, int>;

int main() {
    int V, E;
    cin >> V >> E;

    DSU dsu;
    dsu.init(V);
    Edge edges[E];

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(edges, edges + E);

    int totalWeight = 0;
    for (int i = 0; i < E && V > 1; i++) {
        auto [w, u, v] = edges[i];
        if (!dsu.sameSet(u, v)) {
            totalWeight += w;
            V -= dsu.unite(u, v);
        }
    }
    cout << "MST weight: " << totalWeight << '\n';
}
