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
    ll n, x; cin >> n >> x;
    ll d[n], daux[n];
    for(int i = 0; i < n; i++){
        cin >> d[i];
        daux[i] = d[i] * (d[i] + 1) / 2;   
    }
    ll total = d[n-1];
    ll taux = daux[n-1];
    ll tidx = n-1;
    while(total < x){
        tidx--;
        total += d[tidx];
        taux += daux[tidx];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        total += d[i];
        taux += daux[i];
        while(total >= x){
            total -= d[tidx];
            taux -= daux[tidx];
            tidx++;
            if(tidx >= n){
                tidx = 0;
            }
        }
        tidx--;
        if(tidx < 0) tidx = n-1;
        total += d[tidx];
        taux += daux[tidx];
        ll start = total - x;
        ans = max(ans, taux - (start * (start + 1) / 2));
    }
    cout << ans << endl;
    return 0;
}


