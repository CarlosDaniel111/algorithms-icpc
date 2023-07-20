// Encuentra todas las ocurrencias del patron string pat en el string s
// Complejidad temporal: O(|s| + |pat|)

vi PI(const string& s) {
	vi p(SZ(s));
	FOR(i,1,SZ(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi KMP(const string& s, const string& pat) {
	vi p = PI(pat + '\0' + s), res;
	FOR(i,SZ(p)-SZ(s),SZ(p))
		if (p[i] == SZ(pat)) res.push_back(i - 2 * SZ(pat));
	return res;
}

int main() {
    string a = "AABAACAADAABAABAABBAABBBAABA", b = "AABA";
    cout << SZ(KMP(a, b)); // 4
}
