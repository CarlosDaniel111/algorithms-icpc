//Si se tiene un grafo sin peso, usar BFS.

vii graph[MAXN]; //Grafo guardado como lista de adyascencia.
int dist[MAXN];

/*Llena un arreglo (dist), donde dist[i] indica la distancia mínima que
se tiene que recorrer desde un nodo 'x' para llegar al nodo 'i'. */
void dijkstra(int x){
    memset(dist, -1, sizeof dist);
    dist[x] = 0;

    priority_queue<ii, vii, greater<ii>> pq; pq.emplace(0, x);
    while(!pq.empty()){
        auto [du, u] = pq.top();
        pq.pop();

        if(du > dist[u]) continue;

        for(auto &[v, dv] : graph[u]){
            if(du + dv < dist[v]){
                dist[v] = du + dv;
                pq.emplace(dist[v], v);
            }
        }
    }
}