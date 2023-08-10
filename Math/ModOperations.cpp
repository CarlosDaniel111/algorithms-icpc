/**
 * Calcula a * b mod c para cualquier 0 <= a, b <= c <= 7.2 * 10^18
 * Tiempo: O(1)
*/
using ull = unsigned long long;
ull modmul(ull a, ull b, ull MOD) {
    ll ret = a * b - MOD * ull(1.L / MOD * a * b);
    return ret + MOD * (ret < 0) - MOD * (ret >= (ll) MOD); 
}

constexpr ll MOD = 1e9 + 7;
/**
 * Calcula a^b mod m, en O(log n)
 * Si hay riesgo de desbordamiento, multiplicar con modmul
 * Tiempo: O(log b)
 */
ll modpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

/** 
 * Precalculo de modulos inversos para toda x <= LIM.
 * Se asume que LIM <= MOD y que MOD es primo
 * Tiempo: O(LIM)
 */
constexpr LIM = 1e5 + 5;
ll inv[LIM + 1];
inv[1] = 1;
FOR (i, 2, LIM)
    inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;

/**
 * Precalculo de un solo inverso, usa el primer metodo
 * si MOD es primo, y el segundo en caso contrario
 * Tiempo: O(log MOD)
 */
ll modInverse(ll b) { return modpow(b, MOD - 2, MOD) % MOD; }
ll modInverse(ll a) {
    ll x, y, d = euclid(a, MOD, x, y);
    assert(d == 1);
    return (x + MOD) % MOD;
}
