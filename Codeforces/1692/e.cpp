#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, S, a[200000], pfx[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> S;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        if(accumulate(a, a+N, 0) < S){
            moo << -1 << endl;
            continue;
        }
        map<int, int> fo;
        int mx = 0;
        fo[0] = -1;
        pfx[0] = 0;
        for(int i = 0; i < N; i++){
            if(i != 0){
                pfx[i] = pfx[i-1];
            }
            pfx[i] += a[i];
            if(!fo.count(pfx[i])) fo[pfx[i]] = i;
            if(pfx[i] < S) continue;
            mx = max(mx, i - fo[pfx[i] - S]);
        }
        moo << N - mx << endl;
    }
}
