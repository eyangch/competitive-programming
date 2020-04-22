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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];    
        }
        int m = a[0];
        bool sign = (bool)signbit(a[0]);
        ll ans = 0;
        for(int i = 1; i < n; i++){
            if((bool)signbit(a[i]) != sign){
                ans += m;
                m = INT_MIN;
                sign = (bool)signbit(a[i]);
            }
            m = max(m, a[i]);
        }
        ans += m;
        cout << ans << endl;
    }
    return 0;
}


