#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, v[200000], p[200000], Q;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> v[i];
    }
    p[0]= v[0];
    int mx = v[0];
    for(int i = 1; i < N; i++){
        p[i] = p[i-1] + v[i];
        mx = max(mx, p[i] / (i+1) + (p[i] % (i+1) != 0));
    }
    eat >> Q;
    for(int i = 0; i < Q; i++){
        int t; eat >> t;
        if(t < mx){
            moo << -1 << endl;
            continue;
        }
        moo << p[N-1]/t + (p[N-1] % t != 0) << endl;
    }
}
