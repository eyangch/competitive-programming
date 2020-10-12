#include <bits/stdc++.h>
#define f first
#define s second

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

ll MOD = 1e9+7;

ll c2(ll N){
    ll x = (N * (N-1)) / 2LL;
    return x % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N; cin >> N;
    ll h[N], w[N];
    for(ll i = 0; i < N; i++){
        cin >> h[i];
    }
    for(ll i = 0; i < N; i++){
        cin >> w[i];
    }
    ll ans = 0, sum = 0;
    map<ll, ll> mp;
    for(ll i = 0; i < N; i++){
        vi add, rm;
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
            if(it -> f <= h[i]){
                break;
            }
            //cout << "P: " << *it << endl;
            add.push_back(it -> s);
            rm.push_back(it -> f);
        }
        //cout << sum << endl;
        for(ll j : add){
            mp[h[i]] += j;
            mp[h[i]] %= MOD;
            sum += c2(h[i]+1) * (j);
            sum %= MOD;
            //cout << "Supd: " << sum << endl;
        }
        for(ll j : rm){
            ll rmx = mp[j];
            mp.erase(j);
            sum -= c2(j + 1) * (rmx);
            sum = ((sum % MOD)+MOD) % MOD;
        }
        //cout << ans << " " << sum << endl;
        ans += c2(h[i]+1) * c2(w[i]+1);
        ans += w[i] * sum;
        ans %= MOD;
        mp[h[i]] += w[i];
        sum += c2(h[i]+1) * w[i];
        sum %= MOD;
    }
    cout << ans << endl;
    return 0;
}


