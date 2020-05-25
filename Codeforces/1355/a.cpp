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

ll mindigit(ll x){
    ll ret = 9;
    while(x > 0){
        ret = min(ret, x % 10);
        x /= 10;
    }
    return ret;
}

ll maxdigit(ll x){
    ll ret = 0;
    while(x > 0){
        ret = max(ret, x % 10);
        x /= 10;
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        ll a, k; cin >> a >> k;
        for(int i = 1; i < k; i++){
            ll m = mindigit(a) * maxdigit(a);
            if(m == 0){
                break;
            }
            a += m;
        }
        cout << a << endl;
    }
    return 0;
}


