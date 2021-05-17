#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, a[5000];

int dq(int l, int r, int d){
    if(l > r) return 0;
    int mn = 1e9;
    for(int i = l; i <= r; i++){
        mn = min(mn, a[i]);
    }
    int ret = mn - d;
    int prev = l;
    for(int i = l; i <= r; i++){
        if(a[i] == mn){
            ret += dq(prev, i-1, mn);
            prev = i+1;
        }
    }
    ret += dq(prev, r, mn);
    return min(ret, r-l+1);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    moo << dq(0, N-1, 0) << endl;
}
