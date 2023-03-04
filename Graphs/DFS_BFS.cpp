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

vi grafo[MAXN];
bool visited[MAXN];
int n;

void bfs() {
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        cout << s << ' ';
        for (auto u : grafo[s]) {
            if (visited[u])
                continue;
            visited[u] = true;
            q.push(u);
        }
    }
}

void dfs(int s) {
    if (visited[s])
        return;
    visited[s] = true;
    cout << s << ' ';
    for (auto u : grafo[s]) {
        dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    return 0;
}
