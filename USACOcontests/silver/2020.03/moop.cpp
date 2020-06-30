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
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    int n; cin >> n;
    pii xy[n];
    for(int i = 0; i < n; i++){
        cin >> xy[i].first >> xy[i].second;   
    }
    sort(xy, xy + n);
    int pfxmin[n], pfxmax[n];
    pfxmin[0] = xy[0].second;
    pfxmax[n-1] = xy[n-1].second;
    for(int i = 1; i < n; i++){
        pfxmin[i] = min(pfxmin[i-1], xy[i].second);
        pfxmax[n-i-1] = max(pfxmax[n-i], xy[n-i-1].second);
    }
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(pfxmin[i-1] > pfxmax[i]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}


