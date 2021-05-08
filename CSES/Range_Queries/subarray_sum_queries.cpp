#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segt{
    int l, r, mid;
    segt *a, *b;
    int val, rv, lv, sum;
    segt(int vl, int vr, int (&arr)[200000]){
        l = vl, r = vr, mid = (l + r) / 2;
        if(l < r){
            a = new segt(l, mid, arr);
            b = new segt(mid+1, r, arr);
            rv = max(b->rv, b->sum + a->rv);
            lv = max(a->lv, a->sum + b->lv);
            val = max({a->val, b->val, rv, lv, a->rv + b->lv});
            sum = a->sum + b->sum;
        }
        if(l == r){
            val = rv = lv = sum = arr[l];
        }
    }
    void upd(int id, int dv){
        if(l > r || l > id || r < id) return;
        if(l == r){
            val = rv = lv = sum = dv;
        }else{
            a->upd(id, dv);
            b->upd(id, dv);
            rv = max(b->rv, b->sum + a->rv);
            lv = max(a->lv, a->sum + b->lv);
            val = max({a->val, b->val, rv, lv, a->rv + b->lv});
            sum = a->sum + b->sum;
        }
    }
};

int N, M, x[200000];
segt *s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++){
        eat >> x[i];
    }
    s = new segt(0, N-1, x);
    for(int i = 0; i < M; i++){
        int K, X; eat >> K >> X;
        s->upd(K-1, X);
        moo << max(0LL, s->val) << endl;
    }
}
