#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, pfx[200001];
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        eat >> s;
        for(int i = 0; i < N; i++){
            pfx[i+1] = pfx[i] + (s[i] == 'W');
        }
        int ans = 1e9;
        for(int i = 0; i <= N-K; i++){
            ans = min(ans, pfx[i+K] - pfx[i]);
        }
        moo << ans << endl;
    }
}
