/*
ID: sireric1
LANG: C++11
TASK: fence9
*/

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
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);
    double N, M, P; cin >> N >> M >> P;
    double xslope1 = N / M, xslope2 = (N-P) / M;
    int ans = 0;
    for(double i = 1; i < M; i++){
        ans += ceil(xslope2 * i + P) - (int)(xslope1 * i + 1);
    } 
    cout << ans << endl;
    return 0;
}


