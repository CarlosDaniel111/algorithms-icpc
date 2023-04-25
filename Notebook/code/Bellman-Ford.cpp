#define F0R(k, n) for(int k = 0; k < n; k++)
#define ENDL '\n'

int main() {
    int n, m, A, B, W;
    cin >> n >> m;
    tuple<int, int, int> edges[m];
    F0R(i, m) {
        cin >> A >> B >> W;
        edges[i] = make_tuple(A, B, W);
    }
    vi dist(n + 1, INF);

    int x;
    cin >> x;
    dist[x] = 0; // Nodo de inicio
    F0R(i, n) {
        for (auto e : edges) {
            auto [a, b, w] = e;
            dist[b] = min(dist[b], dist[a] + w);
        }
    }

    for (auto e : edges) {
        auto [u, v, weight] = e;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return 0;
        }
    }

    cout << "Shortest distances from source " << x << ENDL;
    FOR(i, n) {
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    }

    return 0;
}
