int n;                   // number of nodes
vector<vector<int>> adj; // adjacency list of graph

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