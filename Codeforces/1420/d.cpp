#include <bits/stdc++.h>
#define f first
#define s second

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

ll MOD = 998244353;
ll fact[300001];

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
    int N, K; cin >> N >> K;
    fact[0] = 1;
    for(int i = 1; i <= 300000; i++){
        fact[i] = fact[i-1] * i % MOD;
    }
    vector<pii> ops;
    for(int i = 0; i < N; i++){
        int l, r; cin >> l >> r;
        ops.push_back(pii(l, 1));
        ops.push_back(pii(r+1, -1));
    }
    sort(ops.begin(), ops.end());
    ll active = 0;
    ll ans = 0;
    for(int i = 0; i < (int)ops.size(); i++){
        if(ops[i].s == 1 && active >= K-1){
            ans += nCr(active, K-1);
            ans %= MOD;
        }
        active += ops[i].s;
    }
    cout << ans << endl;
    return 0;
}


