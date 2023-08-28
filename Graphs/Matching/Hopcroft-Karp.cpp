/**
 * Descripcion: Algoritmo para resolver el problema de maximum bipartite
 * matching. Los nodos para c1 y c2 deben comenzar desde el indice 1
 * Tiempo: O(sqrt(|V|) * E)
 */

int dist[MAXN], pairU[MAXN], pairV[MAXN], c1, c2;
vi graph[MAXN];

bool bfs() {
    queue<int> q;

    for (int u = 1; u <= c1; u++) {
        if (!pairU[u]) {
            dist[u] = 0;
            q.push(u);
        } else
            dist[u] = INF;
    }

    dist[0] = INF;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] < dist[0]) {
            for (int v : graph[u]) {
                if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    return dist[0] != INF;
}

bool dfs(int u) {
    if (u) {
        for (int v : graph[u]) {
            if (dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v])) {
                    pairU[u] = v;
                    pairV[v] = u;
                    return true;
                }
            }
        }

        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroftKarp() {
    int result = 0;

    while (bfs())
        for (int u = 1; u <= c1; u++)
            if (!pairU[u] && dfs(u))
                result++;

    return result;
}
