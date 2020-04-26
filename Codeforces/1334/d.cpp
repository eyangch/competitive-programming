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
        ll n, l, r; cin >> n >> l >> r;
        ll x = ceil((2 * n - 1 - sqrtl(powl(-2 * n + 1, 2) - 4 * l)) / 2);
        ll y = 2 * (x) * (n - 1) - (x) * (x - 1);
        ll inc = x + 1 + (l - (y - 2 * (n - x)) - 1) / 2;
        while(l <= r){
            for(; l <= y && l <= r; l++){
                if(l % 2 == 1){
                    cout << x << " ";
                }else{
                    cout << inc++ << " ";
                }
            }
            if(l == r && l == n * (n - 1) + 1){
                cout << 1 << " ";
                l++;
            }
            x++;
            inc = x + 1;
            y = 2 * (x) * (n - 1) - (x) * (x - 1);
        }cout << endl;
    }
    return 0;
}


