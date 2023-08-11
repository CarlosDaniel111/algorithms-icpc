// Calculo de coeficientes binomiales, cuando trabajamos con y sin modulos.

// Tiempo: O(MAXN) en el precalculo de inversos modulares y O(1) por query.
constexpr ll MOD = 1e9 + 7;
ll comb(int n, int k) {
    if (n < k)
        return 0;
    return fact[n] * inverse[fact[k]] % MOD * inverse[fact[n - k]] % MOD;
}

/*
 * Se basa en el teorema de lucas, se puede utilizar cuando tenemos una MAXN larga
 * y un modulo m relativamente chico.
 * Tiempo: O(m log_m(n))
 */
ll comb(int n, int k) {
    if (n < k || k < 0)
        return 0;
    if (n == k)
        return 1;
    return comb(n % MOD, k % MOD) * comb(n / MOD, k / MOD) % MOD;
}

/*
 * Se basa en el triangulo de pascal, vale la pena su uso cuando no
 * trabajamos con modulos (pues no tenemos una mejor opcion), usa DP.
 * Tiempo: O(n^2)
 */
ll dp[MAXN][MAXN];
ll comb(int n, int k) {
    if (k > n || k < 0)
        return 0;
    if (n == k || k == 0)
        return 1;
    if (dp[n][k] != -1)
        return dp[n][k];
    return dp[n][k] = comb(n - 1, k) + comb(n - 1, k - 1);
}