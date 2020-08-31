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
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, C; cin >> N >> C;
    ll a[N];
    for(ll i = 0; i < N; i++){
        cin >> a[i];   
    }
    if(C > N){
        ll ans = 0;
        for(ll i = 0; i < N; i++){
            ans += a[i];
        }
        cout << ans << endl;
        return 0;
    }
    ll mins[N], sums[N], rsum = 0;
    multiset<ll> curr;
    for(ll i = 0; i < C; i++){
        curr.insert(a[i]);
        rsum += a[i];
        sums[i] = rsum;
    }
    mins[C-1] = *curr.begin();
    for(ll i = C; i < N; i++){
        rsum += a[i];
        rsum -= a[i-C];
        sums[i] = rsum;
        curr.erase(curr.find(a[i-C]));
        curr.insert(a[i]);
        mins[i] = *curr.begin();
    }
    ll dp[N];
    for(ll i = 0; i < C; i++){
        dp[i] = a[i];
        if(i != 0){
            dp[i] += dp[i-1];
        }
        if(i == C-1){
            dp[i] -= mins[i];
        }
    }
    for(ll i = C; i < N; i++){
        dp[i] = min(sums[i] - mins[i] + dp[i-C], dp[i-1] + a[i]);
    }
    cout << dp[N-1] << endl;
    return 0;
}


