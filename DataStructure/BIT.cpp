/**
 * Descripcion: arbol binario indexado, util para consultas en
 * donde es posible hacer inclusion-exclusion, suma, multiplicacion,
 * etc. Utilizar indices 1-indexados, checar MAX, query -> [1, index]
 * Tiempo: O(log n)
 */

vector<ll> bit;

ll query(int i) {
  ll sum = 0;
  while (i > 0) {
    sum += bit[i];
    i -= i & (-i);
  }
  return sum;
}

void add(int i, int val) {
  while (i < SZ(bit)) {
    bit[i] += val;
    i += i & (-i);
  }
}
