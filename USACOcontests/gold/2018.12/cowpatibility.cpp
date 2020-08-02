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

pair<__int128, ll> hashv(vi v){
    pair<__int128, ll> ret = make_pair(0, v.size());
    __int128 pwr = 1;
    for(ll i = 0; i < (ll)v.size(); i++){
        ret.first += pwr * v[i];
        pwr = pwr * (__int128)1000005;
    }
    return ret;
}

void dfs(ll &N, ll (&flav)[50000][5], vi curr, map<pair<__int128, ll>, ll> &m, ll &idx1, ll &idx2){
    curr.push_back(flav[idx1][idx2]);
    m[hashv(curr)]++;
    for(ll i = idx2+1; i < 5; i++){
        dfs(N, flav, curr, m, idx1, i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    ll N; cin >> N;
    ll flav[50000][5];
    map<pair<__int128, ll>, ll> m;
    vi empty;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < 5; j++){
            cin >> flav[i][j];   
        }
        sort(flav[i], flav[i]+5);
        for(ll j = 0; j < 5; j++){
            dfs(N, flav, empty, m, i, j);
        }
    }
    ll ans = N * (N-1) / 2;
    for(auto it = m.begin(); it != m.end(); it++){
        ll val = (it -> second) * (it -> second - 1)/2;
        if((it -> first).second % 2){
            ans -= val;
        }else{
            ans += val;
        }
    }
    cout << ans << endl;
    return 0;
}


