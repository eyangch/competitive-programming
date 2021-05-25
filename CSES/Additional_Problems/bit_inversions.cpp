#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

struct segt{
    int l, r, m, v = 0, lz = 0;
    segt *a, *b;
    segt(int vl, int vr){
        l = vl, r = vr, m = (l+r)>>1;
        if(l != r) a = new segt(l, m), b = new segt(m+1, r);
    }
    void push(){
        v += lz;
        if(l != r) a->lz += lz, b->lz += lz;
        lz = 0;
    }
    void upd(int rl, int rr, int dv){
        if(r < rl || l > rr) return;
        push();
        if(l >= rl && r <= rr){
            lz += dv, push();
        }else{
            a->upd(rl, rr, dv), b->upd(rl, rr, dv);
            a->push(), b->push();
            v = max(a->v, b->v);
        }
    }
    int qry(int rl, int rr){
        push();
        if(r < rl || l > rr) return -1;
        if(l >= rl && r <= rr) return v;
        return max(a->qry(rl, rr), b->qry(rl, rr));
    }
} *sl, *sr;

int N, M;
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> s >> M;
    N = (int)s.size();
    sl = new segt(0, N-1), sr = new segt(0, N-1);
    int prev = 0;
    for(int i = 0; i < N; i++){
        if(i > 0 && s[i] != s[i-1]) prev = i;
        sl->upd(prev, i, 1);
    }
    prev = N-1;
    for(int i = N-1; i >= 0; i--){
        if(i < N-1 && s[i] != s[i+1]) prev = i;
        sr->upd(i, prev, 1);
    }
    for(int i = 0; i < M; i++){
        int x; eat >> x;
        x--;
        int ld = sr->qry(x, x);
        int rd = sl->qry(x, x);
        int rl = x - ld + 1, rr = x + rd - 1;
        sl->upd(rl, x, -rd);
        sr->upd(x, rr, -ld);
        s[x] = (s[x] == '0' ? '1' : '0');
        bool exl = false, exr = false;
        int lld = -1, rrd = -1, rll = -1, rrr = -1;
        if(x > 0 && s[x] == s[x-1]){
            exl = true;
            lld = sr->qry(x-1, x-1);
            rll = x-1 - lld + 1;
        }
        if(x < N-1 && s[x] == s[x+1]){
            exr = true;
            rrd = sl->qry(x+1, x+1);
            rrr = x+1 + rrd - 1;
        }
        if(exl && exr){
            sl->upd(rll, x, rrd + 1);
            sr->upd(x, rrr, lld + 1);
        }else if(exl){
            sl->upd(rll, x, 1);
            sr->upd(x, x, lld + 1);
        }else if(exr){
            sl->upd(x, x, rrd + 1);
            sr->upd(x, rrr, 1);
        }else{
            sl->upd(x, x, 1);
            sr->upd(x, x, 1);
        }
        moo << sr->qry(0, N-1) << " ";
    }
    moo << endl;
}
