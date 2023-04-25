#define F0R(i, n) for(int i = 0; i < n; i++)
const int MAXN = 2e4;
 
//Si no se necesita imprimir la LIS por completo, eliminar p.
int p[MAXN], nums[MAXN];

void print_LIS(int i) {                             // backtracking routine
    if (p[i] == -1) { 
        cout << A[i]; 
        return; 
    }                                               // base case
    print_LIS(p[i]);                                // backtrack
    cout << nums[i];
}

int main() {
    int n;
    cin >> n;
    F0R(i, n) 
        cin >> nums[i];

    int lis_sz = 0, lis_end = 0;
    int L[n], L_id[n];
    F0R (i, n) {
        L[i] = L_id[i] = 0;
        p[i] = -1;
    }
     
    F0R (i, n) { // O(n)
        int pos = lower_bound(L, L + lis_sz, nums[i]) - L;
        L[pos] = nums[i];      // greedily overwrite this
        L_id[pos] = i;        // remember the index too
      
        p[i] = pos ? L_id[pos-1] : -1; // predecessor info
      
        if (pos == lis_sz) {  // can extend LIS?
            lis_sz = pos + 1; // k = longer LIS by +1
            lis_end = i;      // keep best ending i
        }
    }
    cout << lis_sz << ENDL;
}
