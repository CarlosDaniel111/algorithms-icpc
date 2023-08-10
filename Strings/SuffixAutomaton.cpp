/**
 * Description: Used infrequently. Constructs minimal deterministic
 * finite automaton (DFA) that recognizes all suffixes of a string.
 * \texttt{len} corresponds to the maximum length of a string in
 * the equivalence class, \texttt{pos} corresponds to
 * the first ending position of such a string, \texttt{lnk}
 * corresponds to the longest suffix that is in a different class.
 * Suffix links correspond to suffix tree of the reversed string!
 * Time: O(N\log \sum)
 */

struct SuffixAutomaton {
    int N = 1;
    vi lnk{-1}, len{0}, pos{-1};  // suffix link,
    // max length of state, last pos of first occurrence of state
    vector<map<char, int>> nex{1};
    vector<bool> isClone{0};
    // transitions, cloned -> not terminal state
    vector<vi> iLnk;          // inverse links
    int add(int p, char c) {  // ~p nonzero if p != -1
        auto getNex = [&]() {
            if (p == -1) return 0;
            int q = nex[p][c];
            if (len[p] + 1 == len[q]) return q;
            int clone = N++;
            lnk.pb(lnk[q]);
            lnk[q] = clone;
            len.pb(len[p] + 1), nex.pb(nex[q]),
                pos.pb(pos[q]), isClone.pb(1);
            for (; ~p && nex[p][c] == q; p = lnk[p]) nex[p][c] = clone;
            return clone;
        };
        // if (nex[p].count(c)) return getNex();
        // ^ need if adding > 1 string
        int cur = N++;  // make new state
        lnk.emplace_back(), len.pb(len[p] + 1), nex.emplace_back(),
            pos.pb(pos[p] + 1), isClone.pb(0);
        for (; ~p && !nex[p].count(c); p = lnk[p]) nex[p][c] = cur;
        int x = getNex();
        lnk[cur] = x;
        return cur;
    }
    void init(string s) {
        int p = 0;
        for (char x : s) p = add(p, x);
    }  /// add string to automaton
    // inverse links
    void genIlnk() {
        iLnk.resize(N);
        FOR(v, 1, N)
        iLnk[lnk[v]].pb(v);
    }
    // APPLICATIONS
    void getAllOccur(vi& oc, int v) {
        if (!isClone[v]) oc.pb(pos[v]);  // terminal position
        for (auto u : iLnk[v]) getAllOccur(oc, u);
    }
    vi allOccur(string s) {  // get all occurrences of s in automaton
        int cur = 0;
        for (char x : s) {
            if (!nex[cur].count(x)) return {};
            cur = nex[cur][x];
        }
        // convert end pos -> start pos
        vi oc;
        getAllOccur(oc, cur);
        for (auto t : oc) t += 1 - SZ(s);
        sort(ALL(oc));
        return oc;
    }
    vector<ll> distinct;
    ll getDistinct(int x) {
        // # distinct strings starting at state x
        if (distinct[x]) return distinct[x];
        distinct[x] = 1;
        for (auto y : nex[x]) distinct[x] += getDistinct(y.second);
        return distinct[x];
    }
    ll numDistinct() {  // # distinct substrings including empty
        distinct.resize(N);
        return getDistinct(0);
    }
    ll numDistinct2() {  // assert(numDistinct()==numDistinct2());
        ll ans = 1;
        FOR(i, 1, N)
        ans += len[i] - len[lnk[i]];
        return ans;
    }
};

SuffixAutomaton S;
vi sa;
string s;
void dfs(int x) {
    if (!S.isClone[x]) sa.pb(SZ(s) - 1 - S.pos[x]);
    vector<pair<char, int>> chr;
    for (auto t : S.iLnk[x]) chr.pb({s[S.pos[t] - S.len[x]], t});
    sort(ALL(chr));
    for (auto t : chr) dfs(t.second);
}

int main() {
    reverse(ALL(s));
    S.init(s);
    S.genIlnk();
    dfs(0);
}