/**
 * Descripcion: arbol de segmentos persistente que
 * permite consultas de rango de manera eficiente.
 * Una estructura persistente es aquella que guarda
 * sus estados anteriores y puede volver a ellos.
 * Tiempo: O(log n) por consulta
 */

ll arr[MAXN];

ll l[45 * MAXN], r[45 * MAXN], st[45 * MAXN], nodes = 0;

bool hasFlag[45 * MAXN];
ll flag[45 * MAXN];

ll root[MAXN];

ll newLeaf(ll value) {
    ll p = ++nodes;
    l[p] = r[p] = 0;  // Nodo sin hijos
    st[p] = value;
    return p;
}

ll newParent(ll left, ll right) {
    ll p = ++nodes;
    l[p] = left;
    r[p] = right;
    st[p] = st[left] + st[right];
    return p;
}

ll newLazyKid(ll node, ll x, ll left, ll right) {
    ll p = ++nodes;
    l[p] = l[node];
    r[p] = r[node];
    flag[p] = flag[node];
    hasFlag[p] = true;

    flag[p] = x;
    st[p] = (right - left + 1) * x;  // <-- Si quieres cambiar todo el segmento por x
    // st[p] = st[node]+(right-left+1)*x <-- Si se quiere suma x a todo el segmento

    return p;
}

ll build(ll left, ll right) {
    if (left == right)
        return newLeaf(arr[left]);
    else {
        ll mid = (left + right) / 2;
        return newParent(build(left, mid), build(mid + 1, right));
    }
}

void propagate(ll p, ll left, ll right) {
    if (hasFlag[p]) {
        if (left != right) {
            ll mid = (left + right) / 2;
            l[p] = newLazyKid(l[p], flag[p], left, mid);
            r[p] = newLazyKid(r[p], flag[p], mid + 1, right);
        }
        hasFlag[p] = false;
    }
}

ll update(ll a, ll b, ll x, ll p, ll left, ll right) {
    if (b < left | right < a)
        return p;
    if (a <= left && right <= b)
        return newLazyKid(p, x, left, right);
    propagate(p, left, right);
    ll mid = (left + right) / 2;
    return newParent(update(a, b, x, l[p], left, mid),
                     update(a, b, x, r[p], mid + 1, right));
}

ll query(ll a, ll b, ll p, ll left, ll right) {
    if (b < left || right < a)
        return 0;
    if (a <= left && right <= b)
        return st[p];

    ll mid = (left + right) / 2;
    propagate(p, left, right);
    return (query(a, b, l[p], left, mid) + query(a, b, r[p], mid + 1, right));
}

// revert range [a:b] of p
int rangecopy(int a, int b, int p, int revert, int L = 0, int R = n - 1) {
    if (b < L || R < a) return p;         // keep version
    if (a <= L && R <= b) return revert;  // reverted version
    return newparent(rangecopy(a, b, l[p], l[revert], L, M),
                     rangecopy(a, b, r[p], r[revert], M + 1, R));
}

// Usage: (revert a range [a:b] back to an old version)
// int reverted_root = rangecopy(a, b, root, old_version_root);
