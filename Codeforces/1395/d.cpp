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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, D, M; cin >> N >> D >> M;
    ll a[N];
    for(ll i = 0; i < N; i++){
        cin >> a[i];   
    }
    vi lr, up;
    for(ll i = 0; i < N; i++){
        if(a[i] > M){
            up.push_back(a[i]);
        }else{
            lr.push_back(a[i]);
        }
    }
    sort(lr.begin(), lr.end(), greater<ll>());
    sort(up.begin(), up.end(), greater<ll>());
    if((ll)up.size() == 0){
        ll ans = 0;
        for(ll i = 0; i < N; i++) ans += lr[i];
        cout << ans << endl;
        return 0;
    }
    ll A = (ll)lr.size(), B = (ll)up.size();
    ll x[A+1], y[B+1];
    x[0] = y[0] = 0;
    for(ll i = 1; i <= A; i++){
        x[i] = lr[i-1];
        if(i > 0) x[i] += x[i-1];
    }
    for(ll i = 1; i <= B; i++){
        y[i] = up[i-1];
        if(i > 0) y[i] += y[i-1];
    }
    ll ans = 0;
    for(ll i = 0; i <= N; i++){
        ll uselwr = N - (i-1) * (D+1) - 1;
        if(uselwr < 0 || i > B){
            continue;
        }
        ans = max(ans, y[i] + x[min(A, uselwr)]);
    }
    cout << ans << endl;
    return 0;
}


