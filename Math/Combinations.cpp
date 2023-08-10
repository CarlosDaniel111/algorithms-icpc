/**
 * Calculo de coeficientes binomiales, primer metodo:
 * Tiempo: O(n) de precalculo y O(1) por query
 * El segundo metodo, sirve cuando tenemos una n larga
 * pero un MOD chico, se basa en el teorema de Lucas
 * Tiempo: O(m log_m(n))
 */
constexpr ll MOD = 1e9 + 7;
ll comb(int n, int k) {
    if (n < k)
        return 0;
    return fact[n] * inverse[fact[k]] % MOD * inverse[fact[n - k]] % MOD;
}

ll comb(int n, int k) {
    if (n < k || k < 0)
        return 0;
    if (n == k)
        return 1;
    return comb(n % MOD, k % MOD) * comb(n / MOD, k / MOD) % MOD;
}