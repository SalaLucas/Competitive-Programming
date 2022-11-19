const int MAXN=10;

int n, l;
int timer = 0;
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN];
vector<vector<int>> up;

void dfs(int v, int p){

    tin[v] = timer++;
    cout << '\n';
    up[v][0] = p;
    
    for(int i=1; i<=l; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for(auto c: adj[v]) {
        if(c!=p) dfs(c,v);
    }

    tout[v] = timer++;
    cout << '\n';
}

bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u,int v) {
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;
    for(int i=l; i>=0; --i) {
        if(!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }

    return up[u][0];
}

void preprocess(int root){
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root,root);
}

void edge(int a, int b){
    adj[a].pb(b);
    adj[b].pb(a);
}