const int MAXN = 1e5 + 5;

vi grafo[MAXN];
int dist[MAXN]; //Desde un nodo elegido por nosotros a cualquier otro
//Importante inicializar en -1 para saber si no se ha visitado

void bfs(int node) {
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto u : grafo[s]) {
            if (dist[u] == -1) { //Si no se ha visitado
                dist[u] = dist[s] + 1;
                q.push(u);
            }
        }
    }
}

void dfs(int s) { //asignar previamente dist[nodo_inicial] = 0
    for (auto u : grafo[s]) {
        if (dist[u] == -1) {
            dist[u] = dist[s] + 1;
            dfs(u);
        }
    }
}
