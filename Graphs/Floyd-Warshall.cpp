// Matrix adjacency necessary.
int graph[MAXN][MAXN];
int p[MAXN][MAXN];  // Guardar camino

void floydWarshall() {
    F0R(i, N) {  // Inicializar el camino
        F0R(j, N) {
            p[i][j] = i;
        }
    }

    F0R(k, N) {
        F0R(i, N) {
            F0R(j, N) {
                if (graph[i][k] + graph[k][j] < graph[i][j])  // Solo utilizar si necesitas el camino
                    p[i][j] = p[k][j];

                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    // Now, graph[a][b] has the min distance from node a to node b, for all a and b.
}

void printPath(int i, int j) {
    if (i != j)
        printPath(i, p[i][j]);
    cout << j << " ";
}
