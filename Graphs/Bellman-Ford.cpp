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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, A, B, W;
    cin >> n >> m;
    tuple<int, int, int> edges[m];
    FOR(i, m) {
        cin >> A >> B >> W;
        edges[i] = make_tuple(A, B, W);
    }
    vi dist(n + 1, INF);

    int x;
    cin >> x;
    dist[x] = 0; // Nodo de inicio
    FOR(i, n) {
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
