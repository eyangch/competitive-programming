#include <bits/stdc++.h>

using namespace std;

int N, Q;
int x[200000];
long long BIT[400500];

void upd(int i, long long dv){
    for(; i <= N; i += i&-i){
        BIT[i] += dv;
    }
}

long long qry(int i){
    long long ret = 0;
    for(; i > 0; i -= i&-i){
        ret += BIT[i];
    }
    return ret;
}

int32_t main(){
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> x[i];
        upd(i+1, x[i]);
    }
    for(int i = 0; i < Q; i++){
        int op; cin >> op;
        if(op == 1){
            int k, u; cin >> k >> u;
            int dv = u - x[k-1];
            x[k-1] = u;
            upd(k, dv);
        }else{
            int a, b; cin >> a >> b;
            cout << qry(b) - qry(a-1) << endl;
        }
    }
}
