/**
 * Descripcion: siendo jump[i][j] el ancestro 2^j del nodo i,
 * el binary liftingnos permite obtener el k-esimo ancestro
 * de cualquier nodo en tiempo logaritmico, una aplicacion de
 * esto es para obtener el ancestro comun mas bajo (LCA).
 * Importante inicializar jump[i][0] para todo i.
 * Tiempo: O(n log n) en construccion y O(log n) por consulta 
 */

const LOG_MAXN = 25;
int jump[MAXN][LOG_MAXN];
int depth[MAXN];

void build(int n) {
    memset(jump, -1, sizeof jump);

    dfs(0);

    for (int i = 1; i < LOG_MAXN; i++)
        for (int u = 0; u < n; u++)
            if (jump[u][i - 1] != -1)
                jump[u][i] = jump[jump[u][i - 1]][i - 1];
}

int LCA(int p, int q) {
    if (depth[p] < depth[q])
        swap(p, q);

    int dist = depth[p] - depth[q];
    for (int i = LOG_MAXN - 1; i >= 0; i--)
        if ((dist >> i) & 1)
            p = jump[p][i];

    if (p == q)
        return p;

    for (int i = LOG_MAXN - 1; i >= 0; i--)
        if (jump[p][i] != jump[q][i]) {
            p = jump[p][i];
            q = jump[q][i];
        }

    return jump[p][0];
}
