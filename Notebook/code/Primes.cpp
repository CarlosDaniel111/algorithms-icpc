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
