/**
 * Descripcion: arbol binario indexado, util para consultas en
 * donde es posible hacer inclusion-exclusion, suma, multiplicacion,
 * etc. Utilizar indices 1-indexados, checar MAX, query -> [1, index]
 * Tiempo: O(log n)
 */

int n, bit[MAX];

int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}

void add(int index, int val) {
    while (index <= n) {
        bit[index] += val;
        index += index & (-index);
    }
}
