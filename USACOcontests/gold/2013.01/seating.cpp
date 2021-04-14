#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

struct segt{
    int l, r, m, v = 0;
    segt *a, *b;
    segt(int l, int r){
        this->l = l, this->r = r;
        m = (l + r) / 2;
        if(l < r){
            a = new segt(l, m), b = new segt(m+1, r);
        }
    }
    void upd(int i, int d){
        if(r < i || l > i) return;
        if(l == r){
            v += d;
            return;
        }
        a->upd(i, d), b->upd(i, d);
        v = max(a->v, b->v);
    }
    int qry(int ql, int qr, int x){
        if(r < ql || l > qr || v < x) return -1;
        if(l == r) return l;
        int c = a->qry(ql, qr, x);
        if(c == -1){
            return b->qry(ql, qr, x);
        }
        return c;
    }
};

int N, M, ar[500000];
segt *s;

int32_t main(){
    freopen("seating.in", "r", stdin);
    freopen("seating.out", "w", stdout);
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    s = new segt(0, N-1);
    s->upd(N-1, N);
    ar[N-1] = N;
    int ans = 0;
    for(int i = 0; i < M; i++){
        char x; cin >> x;
        if(x == 'A'){
            int p; eat >> p;
            int cur = s->qry(0, N-1, p);
            if(cur == -1) ans++;
            else{
                s->upd(cur, -p);
                ar[cur] -= p;
            }
        }else{
            int a, b; eat >> a >> b;
            a--, b--;
            int cur = s->qry(a-1, N-1, 1);
            if(cur == -1){
                s->upd(b, b-a+1);
                ar[b] = b-a+1;
                continue;
            }
            while(cur != -1 && cur - ar[cur] + 1 <= b+1){
                a = min(a, cur - ar[cur] + 1);
                b = max(b, cur);
                s->upd(cur, -ar[cur]);
                ar[cur] = 0;
                cur = s->qry(cur, N-1, 1);
            }
            s->upd(b, b-a+1);
            ar[b] = b-a+1;
        }
    }
    moo << ans << endl;
}
