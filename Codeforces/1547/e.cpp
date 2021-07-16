#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, a[300000], t[300000], ac[300000], ans[300000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        fill(ac, ac+N, 0);
        for(int i = 0; i < K; i++){
            eat >> a[i];
            a[i]--;
        }
        for(int i = 0; i < K; i++){
            eat >> t[i];
        }
        for(int i = 0; i < K; i++){
            ac[a[i]] = t[i];
        }
        fill(ans, ans+N, 1e17);
        int curtmp = 1e17;
        for(int i = 0; i < N; i++){
            if(ac[i] > 0) curtmp = min(curtmp, ac[i]);
            ans[i] = min(ans[i], curtmp);
            curtmp++;
        }
        curtmp = 1e17;
        for(int i = N-1; i >= 0; i--){
            if(ac[i] > 0) curtmp = min(curtmp, ac[i]);
            ans[i] = min(ans[i], curtmp);
            curtmp++;
        }
        for(int i = 0; i < N; i++){
            moo << ans[i] << ' ';
        }
        moo << endl;
    }
}
