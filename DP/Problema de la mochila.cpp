/*
Algoritmo: Problema de la mochila
Tipo: DP
Complejidad: O(n^2)

Problema:
Se cuenta con una colección de N objetos donde cada uno tiene un peso y un valor,
y una mochila a la que le caben C unidades de peso.
Escribe un programa que calcule la máxima suma de valores que se puede lograr guardando
objetos en la mochila sin superar su capacidad de peso.

Ejemplo:

Entrada
5
4
4 4
1 3
3 2
9 5
1 3

Salida
6

*/

#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e4 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

ii objeto[MAXN]; // {peso, valor}
int dp[MAXN][MAXN];
int n;

int mochila(int i, int libre) {
    if (libre < 0)
        return -INF;
    if (i == n)
        return 0;
    if (dp[i][libre] != -1)
        return dp[i][libre];

    int opcion1 = mochila(i + 1, libre);
    int opcion2 = objeto[i].second + mochila(i + 1, libre - objeto[i].first);

    return (dp[i][libre] = max(opcion1, opcion2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    /*
    Ejemplo de uso:

    memset(dp,-1,sizeof(dp));
    cout << mochila(0,pmax);
    */

    return 0;
}
