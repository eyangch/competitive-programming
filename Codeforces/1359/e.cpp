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

ll pwr(ll x, ll y, ll m) { 
    if (y == 0){
        return 1;
    }
    ll p = pwr(x, y / 2, m) % m; 
    p *= p;
    p %= m; 
    if(y % 2 == 0){
        return p;
    }else{
        return (x * p) % m;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const ll MOD = 998244353;
    ll N, K; cin >> N >> K;
    ll ans = 0;
    ll fct[N];
    fct[0] = 1;
    for(int i = 1; i <= N; i++){
        fct[i] = (fct[i-1] * i) % MOD;
    }
    for(int i = 1; i <= N/K; i++){
        int n = N/i - 1;
        int r = K-1;
        ans += (fct[n]*(pwr(fct[r]*(fct[n-r]) % MOD, MOD-2, MOD)) % MOD);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}


