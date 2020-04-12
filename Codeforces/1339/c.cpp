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
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n];
        for(ll i = 0; i < n; i++){
            cin >> a[i];    
        }
        ll maxdiff = 0;
        for(ll i = 0; i < n-1; i++){
            maxdiff = max(maxdiff, a[i] - a[i+1]);
            a[i+1] = max(a[i+1], a[i]);
        }
        ll total = 0;
        ll pown = 0;
        while(total < maxdiff){
            total += pow(2, pown);
            pown++;
        }
        cout << pown << endl;
    }
    return 0;
}


