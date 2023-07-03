// Retorna un vector b en donde b[i] es igual a
// max(a[i], a[i + 1], a[i + 2], ..., a[i + p - 1]);

vi max_1D(vi a, int p) {
    vi b(sz(a) - p + 1);
    deque<int> dq;
    F0R(i, sz(a)) {
        while (sz(dq) && a[dq.bk] <= a[i])
            dq.pop_back();
        dq.pb(i);
        if (dq.ft <= i - p)
            dq.pop_front();

        if (i + 1 >= p)
            b[i + 1 - p] = a[dq.ft];
    }
}
