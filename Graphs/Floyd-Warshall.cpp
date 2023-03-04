//Matrix adjacency necessary.
int graph[MAXN][MAXN];

void floydWarshall(){
    FOR (k, N)
        FOR (i, N)
            FOR (j, N)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    //Now, graph[a][b] has the min distance from node a to node b, for all a and b.
}