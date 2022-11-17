#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ll long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN=10;

int n,l;
int timer=0;
vi adj[MAXN];
int tin[MAXN],tout[MAXN];
vector<vi>up;

void dfs(int v,int p){

    tin[v]=timer++;
    dbg("v",v)
    dbg("tin",tin[v]);
    cout<<endl;
    up[v][0]=p;
    
    for(int i=1;i<=l;i++){
        up[v][i]=up[up[v][i-1]][i-1];
    }

    for(auto c: adj[v]){
        if(c!=p)dfs(c,v);
    }

    tout[v]= timer++;
    dbg("v",v)
    dbg("tout",tout[v]);
    cout<<endl;


}

bool is_ancestor(int u,int v){
    return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}

int lca(int u,int v){
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    for(int i=l;i>=0;--i){
        if(!is_ancestor(up[u][i],v)){
            u=up[u][i];
        }
    }

    return up[u][0];
}

void preprocess(int root){
    timer=0;
    l= ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root,root);
}

void edge(int a,int b){
    adj[a].pb(b);
    adj[b].pb(a);
}

int main(){
    sws
    n=10;
    adj[1].pb(7);
    adj[7].pb(1);

    adj[2].pb(7);
    adj[7].pb(2);

    adj[6].pb(7);
    adj[7].pb(6);

    adj[6].pb(5);
    adj[5].pb(6);   
    
    adj[6].pb(3);
    adj[3].pb(6);
    
    adj[1].pb(9);
    adj[9].pb(1);

    adj[9].pb(4);
    adj[4].pb(9);

    adj[4].pb(8);
    adj[8].pb(4);

    // edge(1,2);
    // edge(2,3);
    // edge(3,4);
    // edge(4,5);
    // edge(5,6);
    // edge(6,7);
    // edge(8,7);


    rep(i,1,10){
        cout<<i<<": ";
        for(auto c: adj[i])cout<<c<<" ";
        cout<<endl;
    }

    preprocess(1);

    dbg("lca",lca(8,5));
}