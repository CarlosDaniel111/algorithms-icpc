/**
 * Descripcion: modifica la matriz de adyacencia graph[n][n], 
 * tal que graph[i][j] pasa a indicar el costo minimo para ir 
 * desde el nodo i al j, para cualquier (i, j).
 * Tiempo: O(n^3)
 */
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
}

void printPath(int i, int j) {
    if (i != j)
        printPath(i, p[i][j]);
    cout << j << " ";
}
