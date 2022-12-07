class DSU{
    private:
        vi parents,card;
    public:
        DSU(int n): parents(n+1),card(n+1,1){
            rep(i,1,n+1)parents[i]=i;
        }

        int root(int a){
            if(a==parents[a])return a;
            return parents[a]=root(parents[a]);
        }

        void unite(int a,int b){
            a = root(a);
            b = root(b);

            if(a==b)return;

            if(card[a]<card[b])swap(a,b);

            card[a]+=card[b];
            card[b]=0;
            parents[b]=a;
        }

        bool isSameSet(int a,int b){
            return root(a)==root(b);
        }

};

class Compare{
public:
    bool operator() (Edge a, Edge b)
    {
        return a.ff>=b.ff;
    }
};


int main(){
    sws
    int n,m;
    cin>>n>>m;


    priority_queue<Edge,vector<Edge>,Compare>p;

    rep(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        p.push(mp(w,mp(a,b)));
    }

    DSU dsu(n);
    
    while(!p.empty()){
        Edge edge = p.top();
        p.pop();
        int a = edge.ss.ff,b= edge.ss.ss,w=edge.ff;
        if(!dsu.isSameSet(a,b)){
            dsu.unite(a,b);
            adj[a].pb(mp(b,w));
            adj[b].pb(mp(a,w));
        }
    }

    rep(i,1,n+1){
        cout<<i<<": ";
        for(auto c: adj[i]){
            cout<<"( dest: "<<c.ff<<", w:"<<c.ss<<" ), ";
        }
        cout<<endl;
    }
}