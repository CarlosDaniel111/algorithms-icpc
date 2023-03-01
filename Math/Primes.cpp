#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e5 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

bitset<10000010> bs;
ll criba_tamanio;
vll primes;

void criba(ll n) {
    criba_tamanio = n + 1;
    bs.set(); // Marcar todos primos
    bs[0] = bs[1] = 0;
    for (ll p = 2; p < criba_tamanio; p++) {
        if (bs[p]) {
            for (ll i = p * p; i < criba_tamanio; i += p) {
                bs[i] = false;
            }
            primes.push_back(p);
        }
    }
}

bool isPrime(ll n) {
    if (n <= criba_tamanio)
        return bs[n];
    for (int i = 0; i < (int)primes.size(); i++) {
        if (n % primes[i] == 0)
            return false;
        if (primes[i] * primes[i] > n)
            return true;
    }
    return true;
}

vi factoresPrimos(ll n) {
    vi factores;
    ll index = 0, factor = primes[index];
    while (factor * factor <= n) {
        while (n % factor == 0) {
            n /= factor;
            factores.push_back(factor);
        }
        factor = primes[++index];
    }
    if (n != 1)
        factores.push_back(n);
    return factores;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    return 0;
}
