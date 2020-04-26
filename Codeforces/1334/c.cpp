#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pii a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
        }
        ll bm[n];
        ll pt = 0;
        for(int i = 1; i < n; i++){
            bm[i] = max(0ll, a[i].first - a[i-1].second);
        }
        bm[0] = max(0ll, a[0].first - a[n-1].second);
        for(int i = 0; i < n; i++){
            pt += bm[i];
        }
        ll m = LLONG_MIN;
        for(int i = 0; i < n; i++){
            m = max(m, -a[i].first + bm[i]);
        }
        cout << pt - m << endl;
    }
    return 0;
}


