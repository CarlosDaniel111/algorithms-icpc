const int MAXN = 1e5 + 5;
int n, bit[MAXN];  // Utilizar a partir del 1

int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}

int range_query(int l, int r) {
    return query(r) - query(l - 1);
}

void update(int index, int val) {
    while (index <= n) {
        bit[index] += val;
        index += index & (-index);
    }
}
