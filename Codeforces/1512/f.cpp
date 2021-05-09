#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, C, a[200000], b[200000], days[200000], rem[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> C;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        for(int i = 0; i < N-1; i++){
            eat >> b[i];
        }
        int ans = (C + a[0] - 1) / a[0];
        days[0] = rem[0] = 0;
        for(int i = 1; i < N; i++){
            int req = b[i-1] - rem[i-1];
            int nd = max(0LL, (req + a[i-1] - 1) / a[i-1]);
            days[i] = days[i-1] + nd + 1;
            rem[i] = nd * a[i-1] - req;
            ans = min(ans, days[i] + (C - rem[i] + a[i] - 1) / a[i]);
        }
        moo << ans << endl;
    }
}
