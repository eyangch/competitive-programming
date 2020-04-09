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

int main(){
    ll n; cin >> n;
    ll a[n]; 
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    ll ans = 0;
    ll end = 0;
    for(ll i = 0; a[i] <= n && i < n; i++){
        ans += abs((i + 1) - a[i]);
        end = i;
    }
    for(ll i = end + 1; i < n; i++){
        ans += a[i] - (i + 1);
    }
    cout << ans << endl;
    return 0;
}


