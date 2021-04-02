#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

struct segt{
    int l, r, mid;
    segt *a, *b;
    int val, lazy;
    segt(int vl, int vr){
        l = vl, r = vr, mid = (l+r)/2;
        a = b = NULL;
        if(l < r){
            val = 0;
            lazy = 0;
        }
    }
    void c_a(){
        a = new segt(l, mid);
    }
    void c_b(){
        b = new segt(mid+1, r);
    }
    void push(){
        if(lazy == 0) return;
        if(!a) c_a();
        if(!b) c_b();
        val = (r - l + 1) * lazy;
        if(l < r){
            a->lazy = lazy;
            b->lazy = lazy;
        }
        lazy = 0;
    }
    void upd(int vl, int vr){
        push();
        if(l > r || l > vr || r < vl) return;
        if(l >= vl && r <= vr){
            lazy = 1;
            push();
        }else{
            if(vl <= mid || a){
                if(!a) c_a();
                a->upd(vl, vr);
            }
            if(vr > mid || b){
                if(!b) c_b();
                b->upd(vl, vr);
            }
            val = (a ? a->val : 0) + (b ? b->val : 0);
        }
    }
    int qry(int vl, int vr){
        push();
        if(l > r || l > vr || r < vl) return 0;
        if(l >= vl && r <= vr) return val;
        int ret = 0;
        if(a && vl <= mid){
            if(a->val == mid - l + 1) ret += min(vr, mid) - max(vl, l) + 1;
            else ret += a->qry(vl, vr);
        }
        if(b && vr > mid){
            if(b->val == r - (mid+1) + 1) ret += min(vr, r) - max(vl, mid+1) + 1;
            else ret += b->qry(vl, vr);
        }
        return ret;
    }
};

segt *s;
int M;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    s = new segt(1, 1e9);
    eat >> M;
    int c = 0;
    for(int i = 0; i < M; i++){
        int d, x, y; eat >> d >> x >> y;
        if(d == 1){
            c = s->qry(x+c, y+c);
            moo << c << endl;
        }else{
            s->upd(x+c, y+c);
        }
    }
}
