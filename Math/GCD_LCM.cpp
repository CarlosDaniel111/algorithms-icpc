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

//Siendo b un numero positivo y p el modulo
int modInverse(int b, int p) {
    return fastpow(b, p - 2, p) % p;
}
