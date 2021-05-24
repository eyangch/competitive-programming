#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

struct segt{
    int l, r, m, v, vsum;
    segt *a, *b;
    segt(int vl, int vr){
        l = vl, r = vr, m = (l+r)>>1;
        if(l != r) a = new segt(l, m), b = new segt(m+1, r);
    }
    void upd(int i, int dv, bool type){
        if(r < i || l > i) return;
        if(l == r){
            (!type ? vsum = dv : v = dv);
        }else{
            a->upd(i, dv, type), b->upd(i, dv, type);
            vsum = a->vsum + b->vsum;
            v = min(a->v, b->v);
        }
    }
    int qry(int rl, int rr, bool type){
        if(r < rl || l > rr) return 0;
        if(l >= rl && r <= rr) return (!type ? vsum : v);
        return (!type ? a->qry(rl, rr, type) + b->qry(rl, rr, type) : min(a->qry(rl, rr, type), b->qry(rl, rr, type)));
    }
} *s;

int N, Q, x[100000], y[100000];

int dist(int i1, int i2){
    if(i1 < 0 || i2 >= N) return 0;
    return abs(x[i1] - x[i2]) + abs(y[i1] - y[i2]);
}

int diff(int i){
    return dist(i-1, i+1) - dist(i-1, i) - dist(i, i+1);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    freopen("marathon.in", "r", stdin), freopen("marathon.out", "w", stdout);
    eat >> N >> Q;
    for(int i = 0; i < N; i++){
        eat >> x[i] >> y[i];
    }
    s = new segt(0, N-1);
    for(int i = 0; i < N; i++){
        s->upd(i, dist(i-1, i), 0);
        s->upd(i, diff(i), 1);
    }
    while(Q--){
        char c; eat >> c;
        if(c == 'U'){
            int I, X, Y; eat >> I >> X >> Y;
            x[I-1] = X, y[I-1] = Y;
            s->upd(I-1, dist(I-2, I-1), 0);
            s->upd(I, dist(I-1, I), 0);
            s->upd(I-1, diff(I-1), 1);
            s->upd(I-2, diff(I-2), 1);
            s->upd(I, diff(I), 1);
        }else{
            int I, J; eat >> I >> J;
            int sum = s->qry(I, J-1, 0);
            int sub = s->qry(I, J-2, 1);
            moo << sum + sub << endl;
        }
    }
}
