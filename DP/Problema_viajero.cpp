/*
Problema de agente viajero TSP
El problema del agente viajero consiste en encontrar un recorrido
que visite todos los vértices de una gráfica, sin repetir y a costo mínimo.
Escribe un programa que resuelva la versión del problema en la que el agente
viajero puede comenzar en cualquier vértice y no necesita regresar al vértice inicial.
*/

int dist[MAXN][MAXN];
int dp[MAXN][1 << (MAXN + 1)];
int n;

int solve(int idx, int mask) {
    if (mask == (1 << n) - 1)
        return 0;
    if (dp[idx][mask] != -1)
        return dp[idx][mask];

    int ret = INF;
    F0R(i, n) {
        if ((mask & (1 << i)) == 0) {
            int newMask = mask | (1 << i);
            ret = min(ret, solve(i, newMask) + dist[idx][i]);
        }
    }
    return dp[idx][mask] = ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    memset(dp, -1, sizeof(dp));
    F0R(i, n) {
        F0R(j, n) {
            cin >> dist[i][j];
        }
    }
    int ans = INF;
    F0R(i, n) {
        ans = min(ans, solve(i, (1 << (i))));
    }
    cout << ans;
    return 0;
}
