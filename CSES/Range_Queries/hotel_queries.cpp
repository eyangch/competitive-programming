#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

struct segt{
    int val, l, r, m;
    segt *a, *b;
    segt(int l, int r){
        this->l = l, this->r = r;
        m = (l + r) / 2;
        if(l < r){
            a = new segt(l, m), b = new segt(m+1, r);
        }
        val = 0;
    }
    void upd(int id, int v){
        if(l > id || r < id) return;
        if(l == r) val += v;
        else{
            a->upd(id, v), b->upd(id, v);
            val = max(a->val, b->val);
        }
    }
    int qry(int v){
        if(val < v) return -1;
        if(l == r) return l;
        if(a->val >= v) return a->qry(v);
        else return b->qry(v);
    }
};

int N, M, h[200000];
segt *s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++){
        eat >> h[i];
    }
    s = new segt(0, N-1);
    for(int i = 0; i < N; i++){
        s->upd(i, h[i]);
    }
    for(int i = 0; i < M; i++){
        int r; eat >> r;
        int id = s->qry(r);
        moo << id+1 << " ";
        if(id > -1) s->upd(id, -r);
    }
    moo << endl;
}
