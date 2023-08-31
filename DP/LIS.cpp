/**
 * Descripcion: algoritmo para resolver el problema de la
 * subsecuencia creciente mas larga de un arreglo (LIS) a
 * partir de una estrategia de divide y venceras. Si no
 * es necesario recuperar la subsecuencia, ignorar p.
 * Tiempo: O(n log n)
 */

int n, nums[MAX], L[MAX], L_id[MAX], p[MAX];

void print_LIS(int i) {  // backtracking routine
    if (p[i] == -1) {
        cout << A[i];
        return;
    }                 // base case
    print_LIS(p[i]);  // backtrack
    cout << nums[i];
}

int solve_LIS() {
    int lis_sz = 0, lis_end = 0;
    for (int i = 0; i < n; i++) {
        L[i] = L_id[i] = 0;
        p[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(L, L + lis_sz, nums[i]) - L;
        L[pos] = nums[i];
        L_id[pos] = i;

        p[i] = pos ? L_id[pos - 1] : -1;

        if (pos == lis_sz) {
            lis_sz = pos + 1;
            lis_end = i;
        }
    }
    return lis_sz;
}
