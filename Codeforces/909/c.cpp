#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long ll;

void pforward(ll (&arr)[5000], ll x){
    for(ll i = x; i >= 0; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = 0;
}

int main(){
    ll N;
    cin >> N;
    bool s[5000];
    for(ll i = 0; i < N; i++){
        char x;
        cin >> x;
        if(x == 'f'){
            s[i] = true;
        }else{
            s[i] = false;
        }
    }
    ll dp[2][5000];
    fill(dp[0], dp[1] + 5000, 0);
    dp[0][0] = 1;
    for(ll i = 1; i < N; i++){
        copy(dp[0], dp[0] + N, dp[1]);
        if(s[i-1]){
            pforward(dp[0], i);
        }else{
            ll add = 0;
            for(ll j = i; j >= 0; j--){
                add += dp[1][j];
                add %= MOD;
                dp[0][j] = add;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += dp[0][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
