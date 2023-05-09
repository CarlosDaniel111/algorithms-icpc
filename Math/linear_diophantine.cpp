#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<double, double>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define tcT template <class T tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)

#define ENDL '\n'

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int INF = 1 << 28;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

int gcd(int a, int b,int &x, int &y){
    if(b == 0){
        x= 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

void solution(int a, int b, int n) {
    int x0, y0;
    int g = gcd(a, b, x0, y0);
    if(n%g != 0){
        cout<<"No Solution Exists"<<endl;
        return;
    }
    x0 = x0*n/g;
    y0 = y0*n/g;
    // single valid answer
    cout<<"x = "<<x0<<", y = "<<y0<<endl;
 
    // other valid answers can be obtained through...
    // x = x0 + k*(b/g)
    // y = y0 - k*(a/g)
    for(int k = -3; k <= 3; k++){
        int x = x0 + k*(b/g);
        int y = y0 - k*(a/g);
        cout<<"x = "<<x<<", y = "<<y<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int a = 2, b = 3, n = 7;
    solution(a, b, n);
    return 0;
}
