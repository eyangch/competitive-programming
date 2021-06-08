#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[100];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;

    while(T--){
        eat >> N;
        int g, mx, mn;
        eat >> g;
        mx = g;
        mn = g;
        for(int i = 1; i < N; i++){
            int x; eat >> x;
            mx = max(mx, x); 
            mn = min(mn, x);
        }
        if(mn < 0){
            moo << "nO" << endl;
        }else{
            moo << "yeS" << endl;
            moo << mx+1 << endl;
            for(int i = 0; i <= mx; i++){
                moo << i << " ";
            }
            moo << endl;
        }
    }
}
