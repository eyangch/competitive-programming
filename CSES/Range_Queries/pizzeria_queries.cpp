#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

struct segt{
    int l, r, m, v;
    segt *a, *b;
    segt(int l, int r){
        this->l = l, this->r = r, m = (l+r)>>1;
        if(l < r) a = new segt(l, m), b = new segt(m+1, r);
    }
    void upd(int i, int dv){
        if(r < i || l > i) return;
        if(l == r) v = dv;
        else{
            a->upd(i, dv), b->upd(i, dv);
            v = min(a->v, b->v);
        }
    }
    int qry(int rl, int rr){
        if(r < rl || l > rr) return 2e9;
        if(l >= rl && r <= rr) return v;
        return min(a->qry(rl, rr), b->qry(rl, rr));
    }
};

int N, Q, p[200000];
segt *s1, *s2;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> Q;
    s1 = new segt(0, N-1), s2 = new segt(0, N-1);
    for(int i = 0; i < N; i++){
        eat >> p[i];
        s1->upd(i, p[i] + i);
        s2->upd(i, p[i] - i);
    }
    for(int i = 0; i < Q; i++){
        int type; eat >> type;
        if(type == 1){
            int k, x; eat >> k >> x;
            p[k-1] = x;
            s1->upd(k-1, p[k-1] + k-1);
            s2->upd(k-1, p[k-1] - (k-1));
        }else{
            int k; eat >> k;
            moo << min(s1->qry(k-1, N-1) - (k-1), s2->qry(0, k-1) + k-1) << endl;
        }
    }
}
