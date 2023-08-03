/*
    Un SuffixArray es un array ordenado de todos los sufijos de un string
    Aplicaciones:
     - Encontrar todas las ocurrencias de un substring P dentro del string S - O(|P| log n)
     - Construir el longest common prefix-interval - O(n log n)
     - Contar todos los substring diferentes en el string S - O(n)
     - Encontrar el substring mas largo entre dos strings S y T - O(|S|+|T|)
*/

struct SuffixArray {
    vi SA, LCP;
    string S;
    int n;
    SuffixArray(string &s, int lim = 256) : S(s), n(SZ(s) + 1) {  // O(n log n)
        int k = 0, a, b;
        vi x(ALL(s) + 1), y(n), ws(max(n, lim)), rank(n);
        SA = LCP = y, iota(ALL(SA), 0);

        // Calcular SA
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(ALL(y), n - j);
            FOR(i, 0, n) {
                if (SA[i] >= j) y[p++] = SA[i] - j;
            }
            fill(ALL(ws), 0);
            FOR(i, 0, n) {
                ws[x[i]]++;
            }
            FOR(i, 1, lim) {
                ws[i] += ws[i - 1];
            }
            for (int i = n; i--;) SA[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[SA[0]] = 0;
            FOR(i, 1, n) {
                a = SA[i - 1];
                b = SA[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
            }
        }

        // Calcular LCP (longest common prefix)
        FOR(i, 1, n) {
            rank[SA[i]] = i;
        }
        for (int i = 0, j; i < n - 1; LCP[rank[i++]] = k)
            for (k &&k--, j = SA[rank[i] - 1]; s[i + k] == s[j + k]; k++)
                ;
    }

    int lower(string &sub) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int res = S.compare(SA[mid], SZ(sub), sub);
            (res >= 0) ? r = mid : l = mid + 1;
        }
        return l;
    }

    int upper(string &sub) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int res = S.compare(SA[mid], SZ(sub), sub);
            (res > 0) ? r = mid : l = mid + 1;
        }
        if (S.compare(SA[r], SZ(sub), sub) != 0) --r;
        return r;
    }

    bool subStringSearch(string &sub) {  // O(|sub| log n)
        int L = lower(sub);
        if (S.compare(SA[L], SZ(sub), sub) != 0) return 0;
        return 1;
    }

    int countSubString(string &sub) {  // O(|sub| log n)
        return upper(sub) - lower(sub) + 1;
    }

    ll countDistinctSubstring() {  // O(n)
        ll result = 0;
        FOR(i, 1, n) {
            result += ll(n - SA[i] - 1 - LCP[i]);
        }
        return result;
    }

    string longestCommonSubstring(int lenS, int lenT) {  // O(n)
        int maximo = -1, indice = -1;
        FOR(i, 2, n) {
            if ((SA[i] > lenS && SA[i - 1] < lenS) || (SA[i] < lenS && SA[i - 1] > lenS)) {
                if (LCP[i] > maximo) {
                    maximo = LCP[i];
                    indice = SA[i];
                }
            }
        }
        return S.substr(indice, maximo);
    }

    vi constructRSA() {
        vi RSA(n);
        FOR(i, 0, n) {
            RSA[SA[i]] = i;
        }
        return RSA;
    }
};