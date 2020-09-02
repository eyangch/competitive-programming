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

ll ans[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M, dx, dy; cin >> N >> M >> dx >> dy;
    if(N == 1){
        cout << "0 0" << endl;
        return 0;
    }
    ll curr = 0;
    ll cnt = 0;
    while(curr != 1){
        curr += dy;
        curr %= N;
        cnt++;
    }
    ll deltax = (cnt * dx) % N; //cout << deltax << endl;
    for(ll i = 0; i < M; i++){
        ll x, y; cin >> x >> y;
        ll at = (deltax * y) % N;
        ll diff = (x - at + N) % N;
        //cout << x << " " << y << " " << at << " " << diff << endl;
        ans[diff]++;
    }
    ll maxn = 0;
    ll maxidx = 0;
    for(ll i = 0; i < N; i++){
        if(ans[i] > maxn){
            maxn = ans[i];
            maxidx = i;
        }
    }
    cout << maxidx << " 0" << endl;
    return 0;
}


