#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define f first
#define s second

using namespace std;

struct segt{
    int mn[400005], mx[400005];
    void build(int i, int l, int r, int (&p)[100001]){
        if(l == r){
            mn[i] = mx[i] = p[l];
        }else{
            build(i*2, l, (l+r)/2, p);
            build(i*2+1, (l+r)/2+1, r, p);
            mn[i] = min(mn[i*2], mn[i*2+1]);
            mx[i] = max(mx[i*2], mx[i*2+1]);
        }
    }
    int qry(int i, int l, int r, int rl, int rr, bool m){
        if(l > rr || r < rl) return (m ? -1e17 : 1e17);
        if(l >= rl && r <= rr) return (m ? mx[i] : mn[i]);
        if(l == r){
            return mn[i];
        }
        int a = qry(i*2, l, (l+r)/2, rl, rr, m);
        int b = qry(i*2+1, (l+r)/2+1, r, rl, rr, m);
        return (m ? max(a, b) : min(a, b));
    }
};

int N, Q, a[100000], b[100000], p[100001];
segt s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> Q;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    for(int i = 0; i < N; i++){
        eat >> b[i];
    }
    p[0] = 0;
    for(int i = 1; i <= N; i++){
        p[i] = p[i-1] + (b[i-1] - a[i-1]);
    }
    s.build(1, 0, N, p);
    for(int i = 0; i < Q; i++){
        int l, r; eat >> l >> r;
        if(p[r] != p[l-1]){
            moo << -1 << endl;
            continue;
        }
        int mn = s.qry(1, 0, N, l, r, 0);
        int mx = s.qry(1, 0, N, l, r, 1);
        if(mn - p[l-1] < 0){
            moo << -1 << endl;
            continue;
        }
        moo << mx - p[l-1] << endl;
    }
}
