#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segt{
    int l, r, m, v, ly;
    char c = '0';
    segt *a, *b;
    segt(int l, int r, int ly){
        this->l = l, this->r = r, m = (l+r)>>1, this->ly = ly;
        if(l < r) a = new segt(l, m, ly+1), b = new segt(m+1, r, ly+1);//, v = a->v;
        //else v = 1;
    }
    void upd(int i, char t){
        int sb = 64 - __builtin_clzll(i);
        if(l == r){
            //moo << "F2" << endl;
            c = t;
            if(c == '?') v = 2;
            else v = 1;
        }else if((i>>ly) == 0){
            //moo << "F" << endl;
            c = t;
            if(c == '?') v = a->v + b->v;
            if(c == '0') v = a->v;
            if(c == '1') v = b->v;
        }else{
            int cur = ((i>>(sb-ly-1)) & 1);
            if(cur == 1) a->upd(i, t);
            if(cur == 0) b->upd(i, t);
            if(c == '?') v = a->v + b->v;
            if(c == '0') v = a->v;
            if(c == '1') v = b->v;
        }
        //moo << l << " " << r << " " << i << " " << cur << " " << t << "     " << c << " " << v << endl;
    }
} *seg;

int K, Q;
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> K >> s >> Q;
    seg = new segt(1, (1<<(K-1)), 1);
    for(int i = 0; i < (1<<K)-1; i++){
        seg->upd((1<<K)-1 - i, s[i]);
    }
    while(Q--){
        int p;
        char c;
        eat >> p >> c;
        seg->upd((1<<K) - p, c);
        moo << seg->v << endl;
    }
}
