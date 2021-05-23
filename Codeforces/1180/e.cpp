#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

struct segt{
    int l, r, m, v = 0, lazy = 0;
    segt *a, *b;
    segt(int l, int r){
        this->l = l, this->r = r;
        m = (l+r)>>1;
        if(l < r) a = new segt(l, m), b = new segt(m+1, r);
    }
    void push(){
        v += lazy;
        if(l != r) a->lazy += lazy, b->lazy += lazy;
        lazy = 0;
    }
    void upd(int rl, int rr, int dv){
        push();
        if(r < rl || l > rr) return;
        if(l >= rl && r <= rr){
            lazy += dv, push();
        }else{
            a->upd(rl, rr, dv);
            b->upd(rl, rr, dv);
            v = max(a->v, b->v);
        }
    }
    int qry(int rl, int rr){
        if(r < rl || l > rr) return -1;
        if(l == r) return l;
        push();
        a->push();
        b->push();
        int ret = -2;
        if(b->v > 0){
            ret = b->qry(rl, rr);
        }
        if(a->v > 0 && ret == -2){
            ret = a->qry(rl, rr);
        }
        return ret;
    }
};

int N, M, Q, a[300000], b[300000];
segt *s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++) eat >> a[i];
    for(int i = 0; i < M; i++) eat >> b[i];
    s = new segt(0, 999999);
    for(int i = 0; i < N; i++){
        s->upd(0, --a[i], 1);
    }
    for(int i = 0; i < M; i++){
        s->upd(0, --b[i], -1);
    }
    eat >> Q;
    for(int i = 0; i < Q; i++){
        int A, I, X; eat >> A >> I >> X;
        if(A == 1){
            s->upd(0, a[I-1], -1);
            a[I-1] = X-1;
            s->upd(0, a[I-1], 1);
        }else{
            s->upd(0, b[I-1], 1);
            b[I-1] = X-1;
            s->upd(0, b[I-1], -1);
        }
        moo << s->qry(0, 999999)+1 << endl;
    }
}
