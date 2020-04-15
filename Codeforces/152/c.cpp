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
    int n, m; cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    ll ans = 1;
    for(int i = 0; i < m; i++){
        set<char> nd;
        for(int j = 0; j < n; j++){
            nd.insert(s[j][i]);
        }
        ans *= (ll)nd.size();
        ans %= (ll)1e9 + 7;
    }
    cout << ans << endl;
    return 0;
}


