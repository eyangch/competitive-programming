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
        ll n, x; cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];   
        }
        sort(a, a + n);
        ll add = 0;
        int ans = n;
        for(int i = n-1; i >= 0; i--){
            add += a[i];
            if(add < (n - i) * x){
                ans = (n - 1 - i);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


