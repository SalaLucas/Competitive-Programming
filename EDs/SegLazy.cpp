const int MAX= 2e5+5;
 
vector<ll> lazy(4*MAX,-1);
ll tree[4*MAX], numeros[MAX];
 
void prop(int l, int r, int no){
    if(lazy[no] == -1){
        if(l != r){
            lazy[2*no] = lazy[no];
            lazy[2*no+1] = lazy[no];
        }
        tree[no] = (l-r+1)*lazy[no];
        lazy[no] = -1;
    }
}
 
void build(int l, int r, int no){
    if(l == r){
        tree[no] = numeros[l];
        return;
    }
    int meio = (l+r)/2;
    build(l,meio,2*no);
    build(meio+1,r,2*no+1);
    tree[no] = tree[2*no] + tree[2*no+1];
}

void update(int a, int b, int x, int l, int r, int no){
    prop(l, r, no);
    if(r< a or l > b){
        return;
    }
    if(l>=a and r <=b){
        lazy[no] = x;
        prop(l, r, no);
        return;
    }
    int meio = (l+r)/2;
    update(a,b,x,l,meio,2*no);
    update(a,b,x,meio+1,r,2*no+1);
    tree[no] = tree[2*no+1] + tree[2*no];
}

ll querie(int id, int l, int r, int no){
    prop(l, r, no);
    if(l == r){
        return tree[no];
    }
    int meio = (l+r)/2;
    if(id <= meio){
        return querie(id,l,meio,2*no);
    }
    else{
        return querie(id,meio+1,r,2*no+1);
    }
}