#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll dp[1000000], pfx[1000000];
ll mpows[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    const ll MOD = 1e9+7;
    int N, M, K; cin >> N >> M >> K;
    dp[0] = 1;
    pfx[0] = dp[0];
    mpows[0] = 1;
    for(int i = 1; i <= N; i++){
        mpows[i] = mpows[i-1] * M;
        mpows[i] %= MOD;
    }
    for(int i = 1; i < N; i++){
        dp[i] = (M-1)*pfx[i-1];
        dp[i] %= MOD;
        if(i - K >= 0){
            dp[i] -= ((M-1)*pfx[i-K])%MOD;
        }else if(i-K < -1){
            dp[i] = mpows[i];
        }
        if(dp[i] < 0){
            dp[i] += MOD;
        }
        pfx[i] = pfx[i-1] + dp[i];
        pfx[i] %= MOD;
    }
    ll ans = (mpows[N] - M * dp[N-1]) % MOD;
    while(ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}


