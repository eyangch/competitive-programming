#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll pwr(ll x, ll y, ll MOD){ 
    if (y == 0){
        return 1;
    }
    ll p = pwr(x, y/2, MOD) % MOD; 
    p *= p;
    p %= MOD; 
    if(y % 2 == 0){
        return p;
    }else{
        return (x * p) % MOD;
    }
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    const ll MOD = 1000000007;
    ll N, M, K; cin >> N >> M >> K;
    vi rc[N];
    vi sz[K+1];
    for(int i = 0; i < N; i++){
        int s, c; cin >> s >> c;
        rc[c-1].push_back(s); 
        sz[s].push_back(c-1);
    }
    ll dpsum[K+1];
    fill(dpsum, dpsum+K+1, 0);
    dpsum[0] = 1;
    for(int i = 1; i < K+1; i++){
        dpsum[i] = 0;
        for(int j = 0; j <= i; j++){
            dpsum[i] += sz[j].size() * dpsum[i-j];
            dpsum[i] %= MOD;
        }
    }
    ll csum[100];
    fill(csum, csum+100, 0);
    for(int i = 0; i < M; i++){
        char a; cin >> a;
        csum[(int)a]++;
    }
    ll fans = 1;
    for(int i = 'A'; i <= 'Z'; i++){
        if(csum[i] == 0){
            continue;
        }
        ll ans = 0;
        for(int j = 0; j < N; j++){
            if((int)rc[j].size() == 0){
                continue;
            }
            ll tmpans = 0;
            for(ll k : rc[j]){
                tmpans += dpsum[K-k];
                tmpans %= MOD;
            }
            ans += pwr(tmpans, csum[i], MOD);
            ans %= MOD;
        }
        fans *= ans;
        fans %= MOD;
    }
    cout << fans << endl;
    return 0;
}


