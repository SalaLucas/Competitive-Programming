#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ll unsigned long long 
#define ff first
#define ss second
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = (int)1e5;
vpp adj[MAXN];
vi aux[MAXN];

void dfs(int v,bool visited[],vi* ans){
    visited[v]=true;
    for(int c:aux[v]){
        if(visited[c])continue;
        dfs(c,visited,ans);
    }   
    ans->pb(v);

}

void print(int v){
    cout<<v<<endl;
    for(auto c:aux[v])cout<<c<<" ";
    cout<<endl;
}
int main(){
    sws
    unsigned int n,m;
    cin>>n>>m;

    rep(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
    }

    int distances[n+1];
    bool visited[n+1];

    rep(i,1,n+1){
        distances[i]=INT32_MAX;
        visited[i]=false;
    }
    distances[1]=0;

    priority_queue<pair<pii,int> >p;

    p.push(mp(mp(0,1),0));

    while(!p.empty()){
        int v = p.top().ff.ss;
        int candidate = p.top().ss;
        int dist = -p.top().ff.ff;
        if(dist<=distances[v])aux[candidate].pb(v);
        p.pop();

        if(visited[v])continue; 
        visited[v]=true;

        for(auto c:adj[v]){
            int dest = c.ff,w = c.ss;
            if(distances[dest]>=(distances[v]+w)){
                distances[dest]=distances[v]+w;
                p.push(mp(mp(-distances[dest],dest),v));
            }


        }

    }

    memset(visited,false,n+1);
    vi ans;

    rep(i,1,n+1){
        if(!visited[i]){
            dfs(i,visited,&ans);
        }
    }

    reverse(ans.begin(),ans.end());

    int dp[n+1];
    rep(i,1,n+1)dp[i]=0;
    dp[1]=1;

    for(int c:ans){
        for(auto dest:aux[c]){
            dp[dest]+=dp[c];
        }   
    }

    cout<<endl;
    rep(i,1,n+1)cout<<dp[i]<<" ";
    
}

// Sample
// 5 7
// 1 2 3
// 1 3 5    
// 3 2 2 
// 3 4 2
// 2 4 4 
// 2 5 8
// 4 5 1