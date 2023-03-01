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
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

//Arreglo donde up[i][k], es el 2^k ancestro del nodo i
int up[MAXN][31];

//O(log n), pues un numero tiene a lo mas (log n) bits activados
int query(int node, int k){
    for(int i = 0; i < 31; i++){
        if(k & (1 << i)){
            node = up[node][i];
        }
    }
    return node;
}

int main(){
  ios_base :: sync_with_stdio(0); cin.tie(nullptr);

  int n; cin >> n;
  FOR(i, n){
      int padreDelNodoI; cin >> padreDelNodoI;
      up[i][0] = padreDelNodoI;
  }

  //Se basa en: mi ancestro 4 es a su vez ancestro 2 de mi ancestro 2
  //Precalculo en O(n log n)
  for(int j = 1; j < 31; j++)
      for(int i = 0; i < n; i++)
          up[i][j] = up[up[i][j - 1]][j - 1];
}
