//LCA using binary-lifting (k-th ancestor) technique

const int max_nodes = 100005, log_max_nodes = 30;
int num_nodes, log_num_nodes, root;

vi tree[max_nodes];	// tree[i] contains the children of node i
int up[max_nodes][log_max_nodes+1];	// up[i][j] is the (2^j)-th ancestor of node i, or -1 if that ancestor does not exist
int depth[max_nodes];			// depth[i] is the distance between node i and the root

//Building array depth. 
void DFS(int i, int father) {
    if(father != -1)
      depth[i] = depth[father] + 1;
    for (auto &child : tree[i])
        if (child != father)
            DFS(child, father + 1);
}

int LCA(int p, int q) {
    // ensure node p is at least as deep as node q
    if (depth[p] < depth[q])
	    swap(p, q);

    // "binary search" for the ancestor of node p situated on the same level as q
    for (int i = log_num_nodes; i >= 0; i--)
	    if (depth[p] - (1<<i) >= depth[q])
	        p = up[p][i];

    //if going up with q we found p, then the LCA of q is p
    if (p == q) return p;

    // "binary search" for the LCA, leaving p and q one level below the LCA
    for (int i = log_num_nodes; i >= 0; i--)
	    if (up[p][i] != -1 && up[p][i] != up[q][i]) {
	        p = up[p][i];
	        q = up[q][i];
	}

    return up[p][0];
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(nullptr);

    cin >> num_nodes;
    // read num_nodes, the total number of nodes
    log_num_nodes = 31 - __builtin_clz(num_nodes); //floor of log2(num_nodes)

    for(int i = 0; i < num_nodes; i++){
	    int p; cin >> p;
	    // read p, the parent of node i or -1 if node i is the root
	    up[i][0] = p;
	    if(p != -1)
	        tree[p].push_back(i);
	    else
	        root = i;
    }

    //Building the binary-lifting array 
    for(int j = 1; j <= log_num_nodes; j++)
	    for(int i = 0; i < num_nodes; i++)
	        if(up[i][j-1] != -1)
		        up[i][j] = up[up[i][j-1]][j-1];
	        else
		        up[i][j] = -1;

    // precompute depth
    depth[root] = 0;
    DFS(root, -1);
}
