using ll = long long;
using vl = vector<ll>;

const int MAXN = 1e6 + 5;

ll sieve_size;
vl primes;

// O(n log(log n))
void sieve(int n) {
    vector<bool> is_prime(n + 1, 1);

    is_prime[0] = is_prime[1] = 0;
    for (ll p = 2; p <= n; p++) {
        if (is_prime[p]) {
            for (ll i = p * p; i <= n; i += p) is_prime[i] = 0;
            primes.push_back(p);
        }
    }
}

// Linear Sieve O(n)
void linear_sieve(int N) {
    vector<int> lp(N + 1);
    vector<int> pr;

    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

// Calcular Funcion de Mobius O(n)
void preMobius(int N) {
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    FOR(i, 2, N) {
        if (!check[i]) {  // i es primo
            prime[tot++] = i;
            mu[i] = -1;
        }
        FOR(j, 0, tot) {
            if (i * prime[j] > N) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

// O(sqrt(n))
bool isPrime(ll n) {
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// O(sqrt(n))
vl primeFactors(ll n) {
    vl factors;
    ll idx = 2;
    while (n != 1) {
        while (n % idx == 0) {
            n /= idx;
            factors.pb(idx);
        }
        idx++;
    }
    return 0;
}

// Contar el numero de factores primos del entero N
// O(sqrt(n))
int numPF(ll n) {
    int ans = 0;
    for (int i = 0; (i < (int)primes.size()) && (primes[i] * primes[i] <= n);
         ++i)
        while (n % primes[i] == 0) {
            n /= primes[i];
            ans++;
        }
    return ans + (n != 1);
}
