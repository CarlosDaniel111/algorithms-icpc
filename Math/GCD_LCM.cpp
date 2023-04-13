/*
    En C++14 se puede utilizar el metodo de algorithm
    __gcd(m,n)

    A partir de C++17 se puede utilizar el metodo de numeric
    gcd(m,n)
    lcm(m,n)
*/

int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

ll LCM(int a, int b) { return ((a * b) / GCD(a, b)); }

// Tripleta (d, x, y)
typedef tuple<int, int, int> Triple;

Triple extendedGCD(int a, int b) {
    if (b == 0)
        return Triple({a, 1, 0});
    auto [d, x, y] = extendedGCD(b, a % b);
    return {d, y, x - a / b * y};
}

int modInverse(int a, int m) {
    auto [d, x, y] = extendedGCD(a, m);
    if (d > 1)
        return 0;
    return (x + m) % m;
}
