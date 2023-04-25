const int MAXN = 1e5 + 5;

// Arreglo donde up[i][k], es el 2^k ancestro del nodo i
int up[MAXN][31];

// O(log n), pues un numero tiene a lo mas (log n) bits activados
int query(int node, int k) {
    for (int i = 0; i < 31; i++) {
        if (k & (1 << i)) {
            node = up[node][i];
        }
    }
    return node;
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    F0R(i, n) {
        int padreDelNodoI;
        cin >> padreDelNodoI;
        up[i][0] = padreDelNodoI;
    }

    // Se basa en: mi ancestro 4 es a su vez ancestro 2 de mi ancestro 2
    // Precalculo en O(n log n)
    FOR(j, 1, 31)
    F0R(i, n)
    up[i][j] = up[up[i][j - 1]][j - 1];
}
