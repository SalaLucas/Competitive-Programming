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