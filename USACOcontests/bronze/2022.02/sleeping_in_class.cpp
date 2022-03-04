#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, a[100000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        int sum = 0;
        for(int i = 0; i < N; i++) sum += a[i];
        int ans = 1e16;
        for(int i = 1; i <= sum; i++){
            if(sum % i != 0) continue;
            int cmb = 0;
            int csum = 0;
            int cur = 0;
            for(int j = 0; j < N; j++){
                csum += a[j];
                if(csum > i) cur = 1e16;
                if(csum == i && csum > 0){
                    cmb++;
                    csum = 0;
                }
            }
            cur += N - cmb;
            ans = min(ans, cur);
        }
        moo << (ans == 1e16 ? 0 : ans) << endl;
    }
}
