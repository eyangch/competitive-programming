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
    freopen("squares.in", "r", stdin);
    freopen("squares.out", "w", stdout);
    ll N, K; cin >> N >> K;
    pii c[N];
    for(ll i = 0; i < N; i++){
        cin >> c[i].first >> c[i].second;
    }
    sort(c, c+N);
    ll sPtr = 0, ePtr = 0;
    ll isctArea = 0;
    set<pii> active;
    for(ll i = 0; i < N; i++){
        ll x = c[i].first, y = c[i].second; 
        while(sPtr < N && c[sPtr].first < x+K){
            active.insert(pii(c[sPtr].second, c[sPtr].first));
            sPtr++;
        }
        active.erase(pii(y, x));
        auto it = active.upper_bound(pii(y-K, 1000000));
        if(it == active.end()) continue;
        ll fx = (*it).second, fy = (*it).first;
        if(fy < y+K){
            //cout << x << " " << y << " " << fx << " " << fy << endl;
            if(isctArea > 0){
                cout << -1 << endl;
                //cout << isctArea << endl;
                return 0;
            }
            ll diffx = K-abs(x - fx);
            ll diffy = K-abs(y - fy);
            isctArea = diffx * diffy;
            it++;
            if(it != active.end() && (*it).first < y+K){
                //cout << x << " " << y << " " << K << endl;
                //cout << (*it) << endl;
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << isctArea << endl;
    return 0;
}


