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
    string s; cin >> s;
    int pfx[s.length()];
    pfx[0] = 0;
    for(int i = 1; i < (int)s.length(); i++){
        pfx[i] = pfx[i-1] + (s[i] != s[i-1]);
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        cout << b - a - (pfx[b-1] - pfx[a-1]) << endl;
    }
    return 0;
}


