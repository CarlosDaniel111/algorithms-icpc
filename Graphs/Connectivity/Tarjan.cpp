/**
 * Descripcion: sirve para la busqueda de componentes fuertemente conexos (SCC)
 * Un SCC se define de la siguiente manera: si elegimo cualquier par de vertices u y v
 * en el SCC, podemos encontrar un camino de u a v y viceversa
 * Explicacion: La idea basica del algoritmo de Tarjan es que los SCC forman subarboles
 * en el arbol de expansion de la DFS. Ademas de calcular tin(u) y low(u) para cada vertice,
 * anadimos el vertice u al final de una pila y mantenemos la informacion de que vertices 
 * estan siendo explorados, mediante vi visited. Solo los vertices que estan marcados como 
 * visited (parte del SCC actual) pueden actualizar low(u). Ahora, si tenemos el vertice u 
 * en este arbol de expansion DFS con low(u) = tin(u), podemos concluir que u es la raiz de 
 * un SCC y los miembros de estos SCC se pueden identificar obteniendo el contenido actual 
 * de la pila, hasta que volvamos a llegar al vertice u
 * Tiempo: O(V + E)
 */

int n;                    // number of nodes
vector<vector<int>> adj;  // adjacency list of graph

vector<int> tin, low, visited;
int timer, numSCC;
stack<int> pila;

void tarjanSCC(int u) {
    tin[u] = low[u] = timer++;
    pila.push(u);
    visited[u] = 1;
    for (int to : adj[u]) {
        if (tin[to] == -1)
            tarjanSCC(to);
        if (visited[to])
            low[u] = min(low[u], low[to]);
    }
    if (low[u] == tin[u]) {
        ++numSCC;
        while (1) {
            int v = pila.top();
            pila.pop();
            visited[v] = 0;
            if (u == v)
                break;
        }
    }
}

int main() {
    timer = 0;
    tin.assign(n, -1);
    low.assign(n, 0);
    visited.assign(n, 0);
    while (!pila.empty())
        pila.pop();
    timer = numSCC = 0;
    F0R(i, n) {
        if (tin[i] == -1)
            tarjanSCC(i);
    }
}