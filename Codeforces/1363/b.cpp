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
        string s; cin >> s;
        int n = (int)s.length();
        int pfx[n];
        pfx[0] = (s[0] == '1' ? 1 : 0);
        for(int i = 1; i < n; i++){
            pfx[i] = pfx[i-1] + (s[i] == '1' ? 1 : 0);    
        }
        int ans = min(n - pfx[n-1], pfx[n-1]);
        for(int i = 0; i < n; i++){
            ans = min(ans, min((i+1) - pfx[i], pfx[i]) + min(n - 1 - i - (pfx[n-1] - pfx[i]), (pfx[n-1] - pfx[i])));
        }
        cout << ans << endl;
    }
    return 0;
}


