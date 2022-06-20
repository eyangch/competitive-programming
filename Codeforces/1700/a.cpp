#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        int ans = -M;
        for(int i = 0; i < N; i++){
            ans += (i+1) * M;
        }
        for(int i = 0; i < M; i++) ans += i+1;
        moo << ans << endl;
    }
}
