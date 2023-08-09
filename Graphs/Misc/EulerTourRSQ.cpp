/*
Problema: Tenemos un arbol de n nodos, en donde cada vertice tiene un valor inicial y podemos realizar 2 tipos de queries:
1 - update(x, val): al valor del nodo x agregale val, al de sus hijos restales val, al de los nietos sumales val, etc.
2 - get(x): obtener el valor actual del nodo x.

Approach: Euler tour, asignandole a cada nodo un indice (st[i]) y otro de salida(en[i]) para aplanar el arbol y realizar
operaciones con estructuras de rangos, en este caso usamos el Segment Tree.

Nos basamos en utilizar 2 Segment Trees:
ST1 - Guardar solamente valores de cada nodo en su indice de entrada, caso contrario ST1[i] = 0.
ST2 - Guardar solamente valores de cada nodo en su indice de salida, caso contrario ST2[i] = 0.

Para calcular la suma desde la raiz (0 en este caso) hasta x lo que podemos hacer es inclusion-exclusion, realizando un
ST1.RSQ(0, en[x]) - ST2.RSQ(0, en[x]) si prestamos atencion de manera detallada nos podemos dar cuenta que se van a "borrar"
las aristas que no pertenecen al camino deseado, puesto que hasta ese punto no se ha "subido" por ese camino aun y por lo tanto
los unicos valores que tendra ST2.RSQ(0, en[x]) son los valores "no deseados", es decir, que pueden ser hijos de algun nodo del
camino pero no deben de ser tomados en cuenta para la respuesta.

Ahora imaginemonos que el camino desde la raiz hasta x esta dado por los nodos u0(la raiz), u1, u2, u3, ..., x, una observacion
que se puede hacer es que si el numero de aristas entre u0 y x (o su profundidad) es par, se calcula:
ans[x] = value[x] + sum_camino = value[x] + upd[u0] - upd[u1] + upd[u2] - upd[u3] + ... + upd[x]
Y si es impar:
ans[x] = value[x] + sum_camino = value[x] - upd[u0] + upd[u1] - upd[u2] + upd[u3] + ... + upd[x]

Entonces podemos simplemente actualizar los nodos de nuestros ST de la siguiente forma:
- Si depth[x] es par, hacemos upd[x] += val;
- Si no lo es, hacemos upd[x] -= val;
A final de cuentas lo que logramos es que sum_camino quede de la forma:
upd[u0] - upd[u1] + upd[u2] - upd[u3] + ... + upd[x]
Y como solo difiere por signos depende de la profundidad, multiplicamos por -1 a conveniencia.

Para RMQ en un sub-arbol el problema es mucho mas facil (lol)
*/

vi tree[MAXN];
int val[MAXN], depth[MAXN], st[MAXN], en[MAXN], toursz = 0;
void dfs(int u, int father) {
    st[u] = toursz++;

    for (auto& v : tree[u]) {
        if (v != father) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    en[u] = toursz++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    F0R(i, n)
    cin >> val[i];

    F0R(i, n - 1) {
        int u, v;
        cin >> u >> v;
        tree[u - 1].pb(v - 1);
        tree[v - 1].pb(u - 1);
    }
    depth[0] = 0;
    dfs(0, -1);

    SegmentTree ST1(toursz), ST2(toursz);
    while (q--) {
        int op, x;
        cin >> op >> x;
        x--;
        int parity = ((depth[x] & 1) ? -1 : 1);
        if (op == 1) {
            int val;
            cin >> val;
            ST1.update(st[x], val * parity);
            ST2.update(en[x], -val * parity);
        } else
            cout << (ST1.query(0, st[x]) + ST2.query(0, st[x])) * parity + val[x] << ENDL;
    }

    return 0;
}
