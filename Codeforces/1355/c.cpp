#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll ans = 0;
    ll n = b + c + d;
    ll *pfx = new ll[n];
    fill(pfx, pfx + n, 0);
    for(ll i = a; i <= b; i++){
        pfx[i+b]++;
        pfx[i+c+1]--;
    }
    ll *val = new ll[n];
    val[0] = pfx[0];
    for(ll i = 1; i < n; i++){
        val[i] = val[i-1] + pfx[i];
    }
    ll total = 0;
    for(ll i = c; i < n; i++){
        total += val[i];
    }
    for(ll i = c; i <= d; i++){
        total -= val[i];
        ans += total;
    }
    cout << ans << endl;
    delete[] pfx;
    delete[] val;
    return 0;
}


