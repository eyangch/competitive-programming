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

ll N, K, og[200000];
pii a[11][200000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> K;
    for(ll i = 0; i < N; i++){
        cin >> a[0][i].first;
        og[i] = a[0][i].first;
        a[0][i].first %= K;
        a[0][i].second = i;
        for(ll j = 1; j < 11; j++){
            a[j][i].first = (a[j-1][i].first * 10) % K;
            a[j][i].second = i;
        }
    }
    for(ll i = 0; i < 11; i++){
        sort(a[i], a[i]+N);
    }
    ll ans = 0;
    ll prev = -1;
    for(ll i = 0; i < N; i++){
        ll id = a[0][i].second;
        ll val = a[0][i].first;
        ll len = to_string(og[id]).length();
        auto it1 = upper_bound(a[len],a[len]+N, pii((K-val)%K, INT_MAX));
        auto it2 = lower_bound(a[len],a[len]+N, pii((K-val)%K, 0));
        if(it1 - it2 < 0) continue;
        for(ll j = 0; j < len; j++){
            val *= 10;
            val %= K;
        }
        if((val + a[0][i].first) % K == 0){
            ans--;
        }
        ans += it1 - it2;
    }
    cout << ans << endl;
    return 0;
}


