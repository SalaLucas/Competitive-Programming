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
#define pq xpriority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5;
vi adj[MAXN];
bool visited[MAXN];

void dfs(int v,vi* ans){
    visited[v]=true;
    for(int c:adj[v]){
        if(visited[c])continue;
        dfs(c,ans);
    }   
    ans->pb(v);

}

int main(){
    int n,m;
    cin>>n>>m;

    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }

    vi topSort;

    rep(i,1,n+1){
        if(visited[i])continue;
        dfs(i,&topSort);
    }
    reverse(topSort.begin(),topSort.end());

    output(topSort);
}

// Sample:
// 6 7
// 1 2
// 2 3
// 3 6 
// 1 4
// 4 5
// 5 2
// 5 3
