const int MAXN = 100000;
int t[MAXN +1];
int n;

void build(int a[]) {
    copy(a,a+n+1,t);

    for(int i=1; i<n+1; i++) {
        int p = i + (i&-i);
        if(p<n) {
            t[p] += t[i];
        }
    }
}

void update(int pos, int newValue) {
    while(pos<n) {
        t[pos] += newValue;
        pos += (pos&-pos);
    }
}

int sum(int a) {
    int ans=0;
    while(a>0) {
        ans += t[a];
        a -= (a&-a);
    }
    return ans;
}

int sum(int l, int r) {
    return sum(r) - sum(l-1);
}


    /*  MAIN
    *   Recebe entrada e
    *   aloca no array a
    *   int delta = newValue-a[pos+1];
    */
   