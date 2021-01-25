#include <bits/stdc++.h>
#define int long long

using namespace std;

long long MOD = 1e9+7;

long long N;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    long long ans = 0;
    for(int i = 1; i <= N; i++){
        if(N / i != N / (i+1)){
            ans += N/i * i;
        }else{
            int x = N / (N/i);
            int y = 0;
            if(x % 2 == 0){
                y = (x/2) % MOD * ((x+1) % MOD) % MOD;
            }else{
                y = (x+1) / 2 % MOD * (x % MOD) % MOD;
            }
            int z = 0;
            int w = i-1;
            if(w % 2 == 0){
                z = (w/2) % MOD * ((w+1) % MOD) % MOD;
            }else{
                z = (w+1) / 2 % MOD * (w % MOD) % MOD;
            }
            y = ((y - z) % MOD + MOD) % MOD;
            ans += y * (N/i) % MOD;
            i = x;
        }
        ans %= MOD;
    }
    cout << ans << endl;
}
