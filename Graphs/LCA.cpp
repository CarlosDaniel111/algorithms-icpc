const LOG_MAXN = 25;
vi tree[MAXN];
int jump[MAXN][LOG_MAXN];
int depth[MAXN];

// DFS para calcular la profundidad y guardar el padre directo en salto[u][0]
void dfs(int u, int padre = -1, int d = 0) {
    depth[u] = d;
    jump[u][0] = padre;
    for (auto &hijo : tree[u])
        if (hijo != padre)
            dfs(hijo, u, d + 1);
}

void build(int n) {
    memset(jump, -1, sizeof jump);
    
    dfs(0);

    // Construccion del binary-lifting
    for (int i = 1; i < LOG_MAXN; i++)
        for (int u = 0; u < n; u++)
            if (jump[u][i - 1] != -1)
                jump[u][i] = jump[jump[u][i - 1]][i - 1];
}

int LCA(int p, int q) {
    if (depth[p] < depth[q])
        swap(p, q);

    int dist = depth[p] - depth[q]; // Distancia necesaria para estar en la misma profundidad
    FORR(i, LOG_MAXN)
    if ((dist >> i) & 1)
        p = jump[p][i];

    if (p == q) // Verificar si el ancestro es la misma profundidad
        return p;

    // Busqueda por saltos binarios
    FORR(i, LOG_MAXN)
    if (jump[p][i] != jump[q][i]) {
        p = jump[p][i];
        q = jump[q][i];
    }

    return jump[p][0];
}
