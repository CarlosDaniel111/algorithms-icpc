const int MAXN = 1e5 + 5;

// Arreglo donde up[i][k], es el 2^k ancestro del nodo i
int salto[MAXN][31];

// O(log n), pues un numero tiene a lo mas (log n) bits activados
int query(int node, int k) {
    for (int i = 0; i < 31; i++) 
        if (k & (1 << i)) 
            node = salto[node][i];
    return node;
}

int main() {
    int n;
    cin >> n;
    F0R(i, n) {
        int padreDelNodoI;
        cin >> padreDelNodoI;
        salto[i][0] = padreDelNodoI;
    }

    // Se basa en: mi ancestro 4 es a su vez ancestro 2 de mi ancestro 2
    // Precalculo en O(n log n)
    FOR(j, 1, 31)
        F0R(i, n)
            salto[i][j] = salto[salto[i][j - 1]][j - 1];
    //TENER CUIDADO SI salto[i][j] = -1
}
