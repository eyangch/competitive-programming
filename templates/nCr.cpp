#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

ll MOD = 1e9+7;
ll fact[100000];

ll fexp(ll a, ll b){
    ll ans = 1;
    for(int i = 0; i < 35; i++){
        if(b&(1LL<<i)){
            ans *= a;
        }
        a *= a;
        a %= MOD;
        ans %= MOD;
    }
    return ans;
}

ll nCr(int N, int K){
    return fact[N] * fexp(fact[K] * fact[N-K] % MOD, MOD-2) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    fact[0] = 1;
    for(int i = 1; i < 100000; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
    cout << nCr(20, 7) << endl;
    return 0;
}


