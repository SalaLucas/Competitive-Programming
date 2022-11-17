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
const ll INFLL= 0x3f3f3f3f3f3f3f3f;
vector<pii> adj[MAXN+1];

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

    priority_queue<pair<ll,int> >pq;

    pq.push(mp(0,1));
    ll distances[n+1];
    vector<bool> visited(n+1,false);
    vector<vi> ans(n+1);

    distances[1]=0;
    rep(i,1,n+1){distances[i]=INFLL;}

    while(!pq.empty()){
        int v = pq.top().ss;
        pq.pop();
        if(visited[v]){continue;}
        visited[v]=true;

        for(auto c: adj[v] ){
            int d =c.ff;
            int w = c.ss;
            if(distances[v]+w <distances[d]){
                distances[d]=distances[v]+w;
                pq.push(mp(-distances[d],d));
            }
        }
    }

    if(distances[n]==INFLL){
        cout<<-1;
    }else{
        for(auto c: ans[n]){
            cout<<c<<" ";
        }
    }
}