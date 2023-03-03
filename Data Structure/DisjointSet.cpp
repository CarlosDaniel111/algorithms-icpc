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
typedef vector<pair<int, int>> vii;

//p -> padre directo
int p[MAXN], rankk[MAXN], setSize[MAXN];
int numSets;

int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSame(int i, int j) { return findSet(i) == findSet(j); }
int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

void unite(int i, int j) {
    if (isSame(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if (rankk[x] > rankk[y]) swap(x, y);
    p[x] = y;
    if (rankk[x] == rankk[y]) ++rankk[y];
    setSize[y] += setSize[x];
    --numSets;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    /*INICIALIZAR
    Para todo i en [0, n - 1]
      p[i] = i --> iota(p, p + n, 0)
      setSize[i] = 1 --> fill(setSize, setSize + n, 1)
      numSets = n
    */
    return 0;
}
