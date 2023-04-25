// Matrix adjacency necessary.
int graph[MAXN][MAXN];

void floydWarshall() {
    F0R(k, N)
        F0R(i, N)
            F0R(j, N)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    // Now, graph[a][b] has the min distance from node a to node b, for all a and b.
}
