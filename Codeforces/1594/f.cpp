#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, S, N, K;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> S >> N >> K;
        if(S == K) moo << "YES" << endl;
        else{
            int f = S + K;
            if((S+K)/K % 2 == 0){
                f -= S % K + 1;
            }else{
                f -= K - S % K - 1;
            }
            moo << (f <= 2 * N ? "YES" : "NO") << endl;
        }
    }
}
