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


int32_t main() {
    /* Recebe entrada e
    *  aloca no array a
    */
   
    build(a);

    for(int i=0; i<m; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int pos, newValue;
            cin >> pos >> newValue;
            int delta = newValue-a[pos+1];
            a[pos] = newValue;
            update(pos, delta);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << sum(1, r) << '\n';
        }
    }
}