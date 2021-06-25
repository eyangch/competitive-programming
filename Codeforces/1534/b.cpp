#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[400002];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        a[0] = a[N+1] = 0;
        for(int i = 1; i <= N; i++) eat >> a[i];
        N += 2;
        int ans = 0;
        for(int i = 0; i < N-1; i++){
            ans += abs(a[i] - a[i+1]);
        }
        for(int i = 1; i < N-1; i++){
            int mt = max(a[i-1], a[i+1]);
            ans -= max(0LL, a[i] - mt);
        }
        moo << ans << endl;
    }
}
