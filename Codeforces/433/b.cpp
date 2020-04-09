#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, int> pii;
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
    ll v[n], vsort[n];
    for(ll i = 0; i < n; i++){
        cin >> v[i];   
    }
    copy(v, v + n, vsort);
    sort(vsort, vsort + n);
    ll pfx[n], pfxsort[n];
    pfx[0] = v[0];
    pfxsort[0] = vsort[0];
    for(ll i = 1; i < n; i++){
        pfx[i] = pfx[i-1] + v[i];
        pfxsort[i] = pfxsort[i-1] + vsort[i];
    }
    ll m; cin >> m;
    for(ll i = 0; i < m; i++){
        ll t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            if(l == 1) cout << pfx[r-1] << endl;
            else cout << pfx[r-1] - pfx[l-2] << endl;
        }else{
            if(l == 1) cout << pfxsort[r-1] << endl;
            else cout << pfxsort[r-1] - pfxsort[l-2] << endl;
        }
    }
    return 0;
}


