#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segt{
    int l, r, m, v = 0, lz = 0;
    segt *a, *b;
    segt(int l, int r){
        this->l = l, this->r = r, m = (l+r)/2;
        if(l < r) a = new segt(l, m), b = new segt(m+1, r);
    }
    void push(){
        v += lz;
        if(l < r) a->lz += lz, b->lz += lz;
        lz = 0;
    }
    void upd(int l, int r, int v){
        push();
        if(this->l > r || this->r < l) return;
        if(this->l >= l && this->r <= r){
            lz += v;
            push();
        }else{
            a->upd(l, r, v);
            b->upd(l, r, v);
            this->v = min(a->v, b->v);
        }
    }
};

int N, M, l[300000], r[300000], w[300000], id[300000];
segt *s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++){
        eat >> l[i] >> r[i] >> w[i];
    }
    iota(id, id+N, 0);
    sort(id, id+N, [](int a, int b){
        return w[a] < w[b];
    });
    int en = 0, ans = 1e17;
    s = new segt(1, M-1);
    for(int i = 0; i < N; i++){
        while(s->v == 0){
            if(en >= N) break;
            int cur = id[en++];
            s->upd(l[cur], r[cur]-1, 1);
        }
        if(s->v == 0) break;
        ans = min(ans, w[id[en-1]] - w[id[i]]);
        s->upd(l[id[i]], r[id[i]]-1, -1);
    }
    moo << ans << endl;
}
