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
    int f[m];
    for(int i = 0; i < m; i++){
        cin >> f[i];   
    }
    sort(f, f + m);
    int ans = INT_MAX;
    for(int i = 0; i < m - (n - 1); i++){
        ans = min(ans, f[i + n - 1] - f[i]);
    }
    cout << ans << endl;
    return 0;
}


