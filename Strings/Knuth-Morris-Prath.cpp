/*
Encuentra todas las ocurrencias del patron string p en el 
texto string t. Tiempo de ejecucion es O(n + m), donde n y m
son las longitudes de p y t, respectivamente.
*/
void buildPi(string &p, vi&pi) {
    pi = vi(sz(p));
    int k = -2;
    F0R (i, sz(p)) {
        while (k >= -1 && p[k + 1] != p[i])
            k = (k == -1) ? -2 : pi[k];
        pi[i] = ++k;
    }
}

int KMP(string &t, string& p) {
    vi pi;
    buildPi(p, pi);
    int k = -1;
    F0R (i, sz(t)) {
        while (k >= -1 && p[k + 1] != t[i])
            k = (k == -1) ? -2 : pi[k];
        k++;
        if (k == sz(p) - 1) {
            // p hace match con t[i-m+1, ..., i]
            cout << "matched at index " << i - k << ": ";
            cout << t.substr(i - k, sz(p)) << ENDL;
            k = (k == -1) ? -2 : pi[k];
        }
    }
    return 0;
}

int main() {
    string a = "AABAACAADAABAABA", b = "AABA";
    KMP(a, b);
    //Matches esperados en: 0, 9, 12
}
