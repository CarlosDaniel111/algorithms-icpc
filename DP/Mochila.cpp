/*
Algoritmo: Problema de la mochila
Tipo: DP
Complejidad: O(n^2)

Problema:
Se cuenta con una coleccion de N objetos donde cada uno tiene un peso y un valor,
y una mochila a la que le caben C unidades de peso.
Escribe un programa que calcule la maxima suma de valores que se puede lograr guardando
objetos en la mochila sin superar su capacidad de peso.
*/

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

/*
Ejemplo de uso:

memset(dp,-1,sizeof(dp));
cout << mochila(0,pmax);
*/
