#include <bits/stdc++.h>
#define int long long

using namespace std;

struct segt{
    int vl, vr;
    segt *l, *r;
    int val, lazy;

    segt(int left, int right, int (&ar)[200000]){
        vl = left; vr = right;
        val = lazy = 0;
        if(vl != vr){
            int vm = vl + (vr - vl) / 2;
            l = new segt(vl, vm, ar);
            r = new segt(vm+1, vr, ar);
            val = l->val + r->val;
        }else{
            val = ar[vl];
        }
    }

    ~segt(){
        if(vl != vr){
            delete l;
            delete r;
        }
    }

    void push(){
        val += (vr - vl + 1) * lazy;
        if(vl != vr){
            l->lazy += lazy;
            r->lazy += lazy;
        }
        lazy = 0;
    }

    void upd(int left, int right, int dv){
        push();
        if(vl > vr || left > vr || right < vl){
            return;
        }
        if(vl >= left && vr <= right){
            lazy += dv;
            push();
        }else{
            l->upd(left, right, dv);
            r->upd(left, right, dv);
            val = l->val + r->val;
        }
    }

    int qry(int left, int right){
        if(vl > vr || vl > right || vr < left){
            return 0;
        }
        push();
        if(vl >= left && vr <= right){
            return val;
        }
        int q1 = l->qry(left, right);
        int q2 = r->qry(left, right);
        return q1+q2;
    }
};

struct segt2{
    int vl, vr;
    segt2 *l, *r;
    int val, lazy;

    segt2(int left, int right, int (&ar)[200000]){
        vl = left; vr = right;
        val = lazy = 0;
        if(vl != vr){
            int vm = vl + (vr - vl) / 2;
            l = new segt2(vl, vm, ar);
            r = new segt2(vm+1, vr, ar);
            val = min(l->val, r->val);
        }else{
            val = ar[vl];
        }
    }

    ~segt2(){
        if(vl != vr){
            delete l;
            delete r;
        }
    }

    void push(){
        val += lazy;
        if(vl != vr){
            l->lazy += lazy;
            r->lazy += lazy;
        }
        lazy = 0;
    }

    void upd(int left, int right, int dv){
        push();
        if(vl > vr || left > vr || right < vl){
            return;
        }
        if(vl >= left && vr <= right){
            lazy += dv;
            push();
        }else{
            l->upd(left, right, dv);
            r->upd(left, right, dv);
            val = min(l->val, r->val);
        }
    }

    int qry(int left, int right){
        if(vl > vr || vl > right || vr < left){
            return 1e14;
        }
        push();
        if(vl >= left && vr <= right){
            return val;
        }
        int q1 = l->qry(left, right);
        int q2 = r->qry(left, right);
        return min(q1, q2);
    }
};

int N, Q;
int h[200000];
segt *ts;
segt2 *tmin;

int32_t main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    scanf("%d%d", &N, &Q);
    for(int i = 0; i < N; i++){
        scanf("%d", &h[i]);
    }
    ts = new segt(0, N-1, h);
    tmin = new segt2(0, N-1, h);
    for(int i = 0; i < Q; i++){
        char x; scanf("\n%c", &x);
        if(x == 'S'){
            int a, b; scanf("%lld%lld", &a, &b);
            printf("%lld\n", ts->qry(a-1, b-1));
        }if(x == 'P'){
            int a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
            ts->upd(a-1, b-1, c);
            tmin->upd(a-1, b-1, c);
        }if(x == 'M'){
            int a, b; scanf("%lld%lld", &a, &b);
            printf("%lld\n", tmin->qry(a-1, b-1));
        }
    }
    delete ts;
    delete tmin;
}
