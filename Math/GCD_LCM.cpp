#include <bits/stdc++.h>

#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28;
const long long MOD = 1e9 + 7;
const long long MAXN = 1e5 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

ll LCM(int a, int b) { return ((a * b) / GCD(a, b)); }

//Tripleta (d, x, y)
typedef tuple<int, int, int> Triple;

Triple extendedGCD(int a, int b){
    if (b == 0) return Triple({a, 1, 0});
    auto [d, x, y] = extendedGCD(b, a % b);
    return {d, y, x - a/b * y};
}

int modInverse(int a, int m){
    auto [d, x, y] = extendedGCD(a, m);
    if (d > 1) return 0;
    return (x + m) % m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    return 0;
}
