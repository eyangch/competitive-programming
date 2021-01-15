#include <bits/stdc++.h>

using namespace std;

struct segt{    
    int l, r;
    segt *a, *b;
    int val;

    segt(int vl, int vr, int (&arr)[200000]){
        l = vl, r = vr;
        if(l < r){
            a = new segt(l, (l+r)/2, arr);
            b = new segt((l+r)/2+1, r, arr);
            val = min(a->val, b->val);
        }
        if(l == r){
            val = arr[l-1];
        }
    }
    
    void upd(int id, int dv){
        if(l > r || l > id || r < id) return;
        if(l == r){
            val = dv;
        }else{
            a->upd(id, dv);
            b->upd(id, dv);
            val = min(a->val, b->val);
        }
    }

    int qry(int vl, int vr){
        if(l > r || l > vr || r < vl){
            return 1e9;
        }
        if(l >= vl && r <= vr){
            return val;
        }
        return min(a->qry(vl, vr), b->qry(vl, vr));
    }
};

segt *s;
int N, Q;
int x[200000];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    s = new segt(1, N, x);
    for(int i = 0; i < Q; i++){
        int op; cin >> op;
        if(op == 1){
            int k, u; cin >> k >> u;
            s->upd(k, u);
        }else{
            int a, b; cin >> a >> b;
            cout << s->qry(a, b) << endl;
        }
    }
}
