#define LSOne(S) ((S) & -(S))

class FenwickTree {
  private:
    vll ft;

  public:
    FenwickTree(int m) { ft.assign(m + 1, 0); } // Constructor de ft vacio

    void build(const vll &f) {
        int m = (int)f.size() - 1;
        ft.assign(m + 1, 0);
        FOR(i, 1, m + 1) {
            ft[i] += f[i];
            if (i + LSOne(i) <= m)
                ft[i + LSOne(i)] += ft[i];
        }
    }

    FenwickTree(const vll &f) { build(f); } // Constructor de ft basado en otro ft

    FenwickTree(int m, const vi &s) { // Constructor de ft basado en un vector int
        vll f(m + 1, 0);
        F0R(i, (int)s.size()) {
            ++f[s[i]];
        }
        build(f);
    }

    ll query(int j) { // return query(1,j);
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll query(int i, int j) {
        return query(j) - query(i - 1);
    }

    void update(int i, ll v) {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }

    int select(ll k) {
        int p = 1;
        while (p * 2 < (int)ft.size())
            p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i + p]) {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

class RUPQ { // Arbol de Fenwick de consulta de punto y actualizacion de rango
  private:
    FenwickTree ft;

  public:
    RUPQ(int m) : ft(FenwickTree(m)) {}

    void range_update(int ui, int uj, ll v) {
        ft.update(ui, v);
        ft.update(uj + 1, -v);
    }

    ll point_query(int i) {
        return ft.query(i);
    }
}

class RURQ { // Arbol de Fenwick de consulta de rango y actualizacion de rango
  private:
    RUPQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {}

    void range_update(int ui, int uj, ll v) {
        rupq.range_update(ui, uj, v);
        purq.update(ui, v * (ui - 1));
        purq.update(uj + 1, -v * uj);
    }

    ll query(int j) {
        return ruqp.point_query(j) * j -
               purq.query(j);
    }

    ll query(int i, int j) {
        return query(j) - query(i - 1);
    }
}

// Implementacion
vll f = {0, 0, 1, 0, 1, 2, 3, 2, 1, 1, 0}; // index 0 siempre sera 0
FenwickTree ft(f);
printf("%lld\n", ft.rsq(1, 6));  // 7 => ft[6]+ft[4] = 5+2 = 7
printf("%d\n", ft.select(7));    // index 6, query(1, 6) == 7, el cual es >= 7
ft.update(5, 1);                 // update {0,0,1,0,2,2,3,2,1,1,0}
printf("%lld\n", ft.rsq(1, 10)); // 12
printf("=====\n");
RUPQ rupq(10);
RURQ rurq(10);
rupq.range_update(2, 9, 7); // indices en [2, 3, .., 9] actualizados a +7
rurq.range_update(2, 9, 7);
rupq.range_update(6, 7, 3); // indices 6&7 son actualizados a +3 (10)
rurq.range_update(6, 7, 3);
// idx = 0 (unused) | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10
// val = -          | 0 | 7 | 7 | 7 | 7 |10 |10 | 7 | 7 | 0
for (int i = 1; i <= 10; i++)
    printf("%d -> %lld\n", i, rupq.point_query(i));
printf("RSQ(1, 10) = %lld\n", rurq.rsq(1, 10)); // 62
printf("RSQ(6, 7) = %lld\n", rurq.rsq(6, 7));   // 20