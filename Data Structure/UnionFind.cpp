const int MAXN = 1e5 + 5;

class UnionFind {
    private: int numSets, parent[MAXN], rank[MAXN], setSize[MAXN];
    public:
        UnionFind(int &N) {
            for(int i = 0; i < N; i++) 
                parent[i] = i;
            numSets = N;
        }
        int get(int i) { //path compression
            return (parent[i] == i) ? i : (parent[i] = get(parent[i]));
        }
        bool isSame(int i, int j) {
            return get(i) == get(j);
        }
        void unite(int i, int j) {
            if(!isSame(i, j)) {
                int x = get(i), y = get(j);
                if (rank[x] > rank[y]) swap(x, y);
                parent[x] = y;
                if (rank[x] == rank[y]) ++rank[y];
                setSize[y] += setSize[x];
                --numSets;
            }
        }
        int sizeOfSet(int i) { return setSize[get(i)]; }
};
