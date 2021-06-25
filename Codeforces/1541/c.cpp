#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, d[100000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> d[i];
        }
        sort(d, d+N);
        int ans = d[N-1];
        int sub = 0;
        for(int i = 1; i < N; i++){
            sub += (d[i] - d[i-1]) * i;
            ans -= sub;
        }
        moo << ans << endl;
    }
}
