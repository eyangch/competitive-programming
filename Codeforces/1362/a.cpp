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
    int t; cin >> t;
    while(t--){
        ll a, b; cin >> a >> b;
        ll x = min(a, b);
        ll y = max(a, b);
        if(y % x != 0LL){
            cout << -1 << endl;
            continue;   
        }
        ll reach = y / x;
        ll ans = log(reach) / log(8);
        if(reach % (ll)pow(8, ans) != 0){
            cout << -1 << endl;
            continue;
        }
        reach /= pow(8, ans);
        ll ans2 = log(reach) / log(4);
        if(reach % (ll)pow(4, ans2) != 0){
            cout << -1 << endl;
            continue;
        }
        reach /= pow(4, ans2);
        ll ans3 = log(reach) / log(2);
        if(reach % (ll)pow(2, ans3) != 0){
            cout << -1 << endl;
            continue;
        }
        cout << ans + ans2 + ans3 << endl;
    }
    return 0;
}


