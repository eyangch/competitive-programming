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

ll dp[2000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod = 1e9+7;
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i < 2000001; i++){
        dp[i] = (dp[i-1] + 2 * dp[i-2] + (i % 3 == 0)) % mod;
    }
    int T; cin >> T;
    while(T--){
        int N; cin >> N;  
        cout << (dp[N] * 4) % mod << endl;
    }
    return 0;
}


