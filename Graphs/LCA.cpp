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

const LOG_MAXN = 25;
vi tree[MAXN];
int salto[MAXN][LOG_MAXN];
int depth[MAXN];

// DFS para calcular la profundidad y guardar el padre directo en salto[u][0]
void dfs(int u, int padre = -1, int d = 0) {
    depth[u] = d;
    salto[u][0] = padre;
    for (auto &hijo : tree[u])
        if (hijo != padre)
            dfs(hijo, u, d + 1);
}

void build(int n) {
    // Inicializar salto en -1
    FOR(i, n)
    FOR(j, LOG_MAXN)
    salto[i][j] = -1;

    dfs(0);

    // Construccion del binary-lifting
    for (int i = 1; i < LOG_MAXN; i++)
        for (int u = 0; u < n; u++)
            if (salto[u][i - 1] != -1)
                salto[u][i] = salto[salto[u][i - 1]][i - 1];
}

int LCA(int p, int q) {
    if (depth[p] < depth[q])
        swap(p, q);

    int dist = depth[p] - depth[q]; // Distancia necesario para estar en la misma profundidad
    FORR(i, LOG_MAXN)
    if ((dist >> i) & 1)
        p = salto[p][i];

    if (p == q) // Verificar si el ancestro es la misma profundidad
        return p;

    // Busqueda por saltos binarios
    FORR(i, LOG_MAXN)
    if (salto[p][i] != salto[q][i]) {
        p = salto[p][i];
        q = salto[q][i];
    }

    return salto[p][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    return 0;
}
