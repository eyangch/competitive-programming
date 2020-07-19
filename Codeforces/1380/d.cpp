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
    ll N, M; cin >> N >> M;
    ll x, k, y; cin >> x >> k >> y; 
    ll a[N], b[M];
    for(ll i = 0; i < N; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < M; i++){
        cin >> b[i];
    }
    vector<pii> sec;
    ll start = 0, bidx = 0;
    for(ll i = 0; i < N; i++){
        if(bidx < M && a[i] == b[bidx]){
            bidx++;
            if(i > start){
                sec.push_back(pii(start, i));
            }
            start = i+1;
        }
    }
    if(bidx < M){
        cout << -1 << endl;
        return 0;
    }
    if(start != N){
        sec.push_back(pii(start, N));
    }
    ll ans = 0;
    for(pii curr : sec){
        ll s = curr.first, e = curr.second;
        ll maxn = 0;
        for(ll i = s; i < e; i++){
            maxn = max(maxn, a[i]);
        }
        ll maxedge = 0;
        if(s > 0){
            maxedge = max(maxedge, a[s-1]);
        }
        if(e < N){
            maxedge = max(maxedge, a[e]);
        }
        ll add = LLONG_MAX;
        if(maxedge > maxn || (e-s) >= k){
            add = min(add, (e-s) / k * x + (e-s) % k * y);
        }
        if(maxedge > maxn){
            add = min(add, (e-s) * y);
        }else if(e-s >= k){
            add = min(add, x + (e-s-k) * y);
        }
        if(add == LLONG_MAX){
            cout << -1 << endl;
            return 0;
        }
        ans += add;
    }
    cout << ans << endl;
    return 0;
}


