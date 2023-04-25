/*
    En C++14 se puede utilizar el metodo de algorithm
    __gcd(m,n)

    A partir de C++17 se puede utilizar el metodo de numeric
    gcd(m,n)
    lcm(m,n)
*/

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

ll lcm(int a, int b) { return ((a * b) / gcd(a, b)); }

ll fastpow(ll a, ll b, ll m) { //(a^b) mod m
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

//Siendo b un entero positivo y p un primo
int modInverse(int b, int p) {
    return fastpow(b, p - 2, p) % p;
}
