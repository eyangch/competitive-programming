#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, a[100000], b[100000], sa[100000], suma[100000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < M; i++){
            eat >> a[i] >> b[i];
        }
        copy(a, a+M, sa);
        sort(sa, sa+M, greater<int>());
        suma[0] = sa[0];
        for(int i = 1; i < M; i++) suma[i] = suma[i-1] + sa[i];
        int ans = sa[min(M-1, N-1)];
        for(int i = 0; i < M; i++){
            int idx = min(N-1, upper_bound(sa, sa+M, b[i], greater<int>()) - sa - 1);
            int g = (a[i] < b[i]);
            ans = max(ans, (idx < 0 ? 0 : suma[idx]) + b[i] * (N-idx-1-g) + g * a[i]);
        }
        moo << ans << endl;
    }
}
