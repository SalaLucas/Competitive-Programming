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