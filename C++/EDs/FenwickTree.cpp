#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MAXN =100000 ;
int t[MAXN +1];
int n;

void build(int a[]){
    copy(a,a+n+1,t);

    rep(i,1,n+1){
        int p = i+ (i&-i);
        if(p<n){
            t[p]+=t[i];
        }

    }
   
}

void update(int pos,int newValue){
   while(pos<n){
        t[pos]+=newValue;
        pos +=(pos&-pos);
   }
}
int sum(int a){
    int ans=0;
    while(a>0){
        ans+=t[a];
        a-=(a&-a);
    }
    return ans;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}


int32_t main(){
    int m;
    cin>>n>>m;
    int a[n+1];
    a[0]=0;

    rep(i,1,n+1){
        cin>>a[i];
    }

    build(a);
s
    rep(i,0,m){
        int op;
        cin>>op;
        if(op==1){
            int pos,newValue;
            cin>>pos>>newValue;
            int delta =newValue-a[pos+1];
            a[pos]=newValue;
            update(pos,delta);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<sum(1,r)<<"\n";
        }
    }
}