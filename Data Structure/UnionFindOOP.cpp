const int MAXN = 1e5 + 5;

class UnionFind {
    private: int p[MAXN], rank[MAXN];
    public:
        UnionFind(int N) {
            for(int i = 0; i < N; i++) {
                p[i] = i;
            }
        }
        int get(int i) {
            return (p[i] == i) ? i : (p[i] = get(p[i]));
        }
        bool isSameSet(int i, int j) {
            return get(i) == get(j);
        }
        void unionSet(int i, int j) {
            if(!isSameSet(i, j)) {
                int x = get(i), y = get(j);
                if(rank[x] > rank[y]) {
                    p[y] = x;
                }else {
                    p[x] = y;
                    if(rank[x] == rank[y]) {
                        rank[y]++;
                    }
                }
            }
        }
};
