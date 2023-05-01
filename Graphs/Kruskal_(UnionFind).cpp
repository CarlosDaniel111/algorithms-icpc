const int MAXN = 1e5 + 5;

class UnionFind {
    public:
        int numSets, parent[MAXN], rank[MAXN], setSize[MAXN];
        UnionFind(int &N) {
            iota(parent, parent + N, 0);
            fill(setSize, setSize + N, 1);
            numSets = N;
        }
        int get(int i) { return (parent[i] == i) ? i : (parent[i] = get(parent[i])); }
        bool isSame(int i, int j) { return get(i) == get(j); }
        
        void unite(int i, int j) {
            if(!isSame(i, j)) {
                int x = get(i), y = get(j);
                if (rank[x] > rank[y]) swap(x, y);
                parent[x] = y;
                if (rank[x] == rank[y]) ++rank[y];
                setSize[y] += setSize[x];
                numSets--;
            }
        }
};

using Edge = tuple<int, int, int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;
    
    UnionFind UF(V);
    Edge edges[V];
    
    F0R(i, E) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(edges, edges + E);

    int totalWeight = 0;
    for (int i = 0; i < E && UF.numSets > 1; i++) {
        auto [w, u, v] = edges[i]; // desempaquetamiento de arista
        if (!UF.isSame(u, v)) {       // Si no estan en el mismo conjunto, la tomamos
            totalWeight += w;
            UF.unite(u, v);
        }
    }
    cout << "MST weight: " << totalWeight << '\n';
    return 0;
}
