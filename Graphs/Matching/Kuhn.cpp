/**
 * Descripcion: Soluciona el problema de maximo emparejamiento bipartito, 
 * se basa en el algoritmo que puede ser pensado como n DFS siendo ejecutadas.
 * Tiempo: O(n^2)
 */
int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    //... reading the graph ...

    mt.assign(k, -1);
    int ans = 0;
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        if (try_kuhn(v)) ans++;
    }

    cout << ans << ENDL;
    for (int i = 0; i < k; ++i)
        if (mt[i] != -1)
            printf("%d %d\n", mt[i] + 1, i + 1);
}
