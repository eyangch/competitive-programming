#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct BIT{
    int ar[800001], N;
    void init(int N){
        this->N = N;
        fill(ar, ar+N, 0);
    }
    void upd(int i, int dv){
        for(; i <= N; i += i&-i) ar[i] += dv;
    }
    int qry(int i){
        int ret = 0;
        for(; i > 0; i -= i&-i) ret += ar[i];
        return ret;
    }
};

int N, a[200000], pfx[200000], a1[200000], a2[200000];
BIT *bit;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> a[i];
        pfx[i] = (i == 0 ? 0 : pfx[i-1]) + a[i];
    }
    bit = new BIT();
    bit->init(800001);
    for(int i = 0; i < N; i++){
        a1[i] = (i == 0 ? 0 : a1[i-1]) + a[i] * i + bit->qry(a[i]);
        for(int j = a[i]; j <= 300000; j += a[i]){
            bit->upd(j, -a[i]);
        }
    }
    bit->init(800001);
    for(int i = 0; i < N; i++){
        a2[i] = (i == 0 ? 0 : a2[i-1] + pfx[i-1]);
        for(int j = a[i]; j <= 300000; j += a[i]){
            a2[i] += (bit->qry(j + a[i] - 1) - bit->qry(j-1)) * j;
        }
        bit->upd(a[i], -1);
    }
    for(int i = 0; i < N; i++){
        moo << a1[i] + a2[i] << ' ';
    }
    moo << endl;
}
