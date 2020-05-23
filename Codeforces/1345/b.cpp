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
    vi cnum;
    for(int i = 1; i * (3 * i + 1) / 2 <= 1000000000; i++){
        cnum.push_back(i * (3 * i + 1) / 2);
    }
    while(t--){
        int n; cin >> n;
        int ans = 0;
        while(n >= 2){
            n -= *(upper_bound(cnum.begin(), cnum.end(), n) - 1);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

