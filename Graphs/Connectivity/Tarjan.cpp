/**
 * Descripcion: sirve para la busqueda de componentes fuertemente conexos (SCC)
 * Un SCC se define de la siguiente manera: si elegimo cualquier par de vertices u y v
 * en el SCC, podemos encontrar un camino de u a v y viceversa
 * Explicacion: La idea basica del algoritmo de Tarjan es que los SCC forman subarboles
 * en el arbol de expansion de la DFS. Ademas de calcular tin(u) y low(u) para cada vertice,
 * anadimos el vertice u al final de una pila y mantenemos la informacion de que vertices
 * estan siendo explorados, mediante vi vis. Solo los vertices que estan marcados como
 * vis (parte del SCC actual) pueden actualizar low(u). Ahora, si tenemos el vertice u
 * en este arbol de expansion DFS con low(u) = tin(u), podemos concluir que u es la raiz de
 * un SCC y los miembros de estos SCC se pueden identificar obteniendo el contenido actual
 * de la pila, hasta que volvamos a llegar al vertice u
 * Tiempo: O(V + E)
 */

vector<vi> g;
vi tin, low, vis;
int timer, numSCC;
stack<int> pila;

void go(int u) {
  tin[u] = low[u] = timer++;
  pila.push(u);
  vis[u] = 1;
  for (int to : g[u]) {
    if (tin[to] == -1) go(to);
    if (vis[to]) low[u] = min(low[u], low[to]);
  }
  if (low[u] == tin[u]) {
    ++numSCC;
    while (1) {
      int v = pila.top();
      pila.pop();
      vis[v] = 0;
      if (u == v) break;
    }
  }
}

int tarjan() {
  tin.assign(n, -1);
  low.assign(n, 0);
  vis.assign(n, 0);
  while (!pila.empty()) pila.pop();
  timer = numSCC = 0;
  FOR (i, 0, n) if (tin[i] == -1) go(i);
  return numSCC;
}