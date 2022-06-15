#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segtree{
    int N, a[4000001], c[4000001], b[1000000], lz[4000001];
    void init(int N){
        this->N = N;
        fill(a, a+4*N+1, 0);
        fill(c, c+4*N+1, 0);
        fill(b, b+N, 0);
        fill(lz, lz+4*N+1, 0);
    }
    void push(int i, int l, int r){
        if(l == r){
            a[i] += lz[i];
            lz[i] = 0;
            return;
        }
        if(c[i] != -1){
            c[i*2] = c[i*2+1] = c[i];
            lz[i*2] += lz[i];
            lz[i*2+1] += lz[i];
            lz[i] = 0;
        }
    }
    void color(int l, int r, int cl, int i=1, int vl=0, int vr=-1){
        if(vr == -1) vr = N-1;
        push(i, vl, vr);
        if(l > vr || r < vl) return;
        if(l <= vl && r >= vr && c[i] != -1){
            lz[i] += b[c[i]];
            lz[i] -= b[cl];
            c[i] = cl;
        }else{
            color(l, r, cl, i*2, vl, (vl + vr) / 2);
            color(l, r, cl, i*2+1, (vl+vr)/2+1, vr);
            if(c[i*2] == c[i*2+1]) c[i] = c[i*2];
            else c[i] = -1;
        }
    }
    int qry(int v, int i=1, int vl=0, int vr=-1){
        if(vr == -1) vr = N-1;
        push(i, vl, vr);
        if(v < vl || v > vr) return 0;
        if(vl == vr){
            return a[i] + b[c[i]];
        }
        return qry(v, i*2, vl, (vl+vr)/2) + qry(v, i*2+1, (vl+vr)/2+1, vr);
    }
};

int N, Q;
segtree S;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> Q;
    S.init(N);
    for(int i = 0; i < Q; i++){
        string s;
        eat >> s;
        if(s[0] == 'C'){
            int l, r, c; eat >> l >> r >> c;
            S.color(l-1, r-1, c-1);
        }else if(s[0] == 'A'){
            int c, x; eat >> c >> x;
            S.b[c-1] += x;
        }else{
            int x; eat >> x;
            moo << S.qry(x-1) << endl;
        }
    }
}
