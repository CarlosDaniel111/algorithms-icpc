/* Segment Tree para calcular la suma entre un intervalo */

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

int arr[MAXN], tree[MAXN * 4];

void buildTree(int index, int start, int end) {
    if (start == end) {
        tree[index] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(2 * index + 1, start, mid);
        buildTree(2 * index + 2, mid + 1, end);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
}

void update(int index, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[index] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update(2 * index + 1, start, mid, idx, val);
        else
            update(2 * index + 2, mid + 1, end, idx, val);

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
}

/*Implementado para obtener suma en un rango, pero es posible usar cualquier 
operacion conmutativa como la multiplicacion, XOR, AND, OR, MIN, MAX, etc.*/
int query(int index, int start, int end, int l, int r) {
    if (r < start || end < l) 
        return 0; //Si ese rango no nos sirve, retornar un valor que no cambie nada

    if (l <= start && end <= r)
        return tree[index];

    int mid = (start + end) / 2;
    int q1 = query(2 * index + 1, start, mid, l, r);
    int q2 = query(2 * index + 2, mid + 1, end, l, r);

    return q1 + q2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    return 0;
}
