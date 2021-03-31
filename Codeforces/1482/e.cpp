#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segt{
    int l, r;
    segt *a, *b;
    int val, lazy;
    segt(int vl, int vr){
        l = vl, r = vr;
        if(l < r){
            a = new segt(l, (l+r)/2);
            b = new segt((l+r)/2+1, r);
            val = max(a->val, b->val);
        }
        if(l == r){
            val = -1e17;
            lazy = -1;
        }
    }
    void push(){
        if(lazy == -1) return;
        val = -1e17;
        if(l < r){
            a->lazy = lazy;
            b->lazy = lazy;
        }
        lazy = -1;
    }
    void fzero(int vl, int vr){
        push();
        if(l > r || vl > vr || l > vr || r < vl) return;
        if(l >= vl && r <= vr){
            lazy = 0;
            push();
        }else{
            a->fzero(vl, vr);
            b->fzero(vl, vr);
            val = max(a->val, b->val);
        }
    }
    void upd(int id, int dv){
        push();
        if(l > r || l > id || r < id) return;
        if(l == r){
            val = max(val, dv);
        }else{
            a->upd(id, dv);
            b->upd(id, dv);
            val = max(a->val, b->val);
        }
    }
    int qry(int vl, int vr){
        push();
        if(l > r || l > vr || r < vl) return -1e17;
        if(l >= vl && r <= vr) return val;
        return max(a->qry(vl, vr), b->qry(vl, vr));
    }
};

int N, h[300000], b[300000];
segt *s, *s2;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> h[i];
    }
    for(int i = 0; i < N; i++){
        eat >> b[i];
    }
    s = new segt(1, N+1); // in progress (only store min height + prev beauty)
    s2 = new segt(1, N+1); // finished (ending height + beauty)
    s->upd(N+1, 0);
    for(int i = 0; i < N; i++){
        int atc = s->qry(h[i], N+1), atc2 = s2->qry(1, N+1);
        s->fzero(h[i], N+1);
        s2->fzero(h[i], N+1);
        s->upd(h[i], max(atc, atc2));
        s2->upd(h[i], max(atc, atc2) + b[i]);
    }
    moo << s2->qry(1, N+1) << endl;
}
