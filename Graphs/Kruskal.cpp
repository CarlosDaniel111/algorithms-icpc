struct DSU { // Indice base 0
    vi e;
    void init(int N) { e = vi(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

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
        auto [w, u, v] = edges[i]; // desempaquetamiento de arista
        if (!UF.sameSet(u, v)) {   // Si no estan en el mismo conjunto, la tomamos
            totalWeight += w;
            V -= UF.unite(u, v);
        }
    }
    cout << "MST weight: " << totalWeight << '\n';
    return 0;
}
