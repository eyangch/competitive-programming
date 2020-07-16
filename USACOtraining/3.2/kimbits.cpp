/*
ID: sireric1
LANG: C++11
TASK: kimbits
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
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    ll N, L, I; cin >> N >> L >> I;
    ll dp[N+1][L+1];
    for(int i = 0; i <= L; i++){
        dp[0][i] = 1;
    }
    dp[1][0] = 1;
    for(int i = 1; i <= L; i++){
        dp[1][i] = 2;
    }
    for(int i = 2; i <= N; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= L; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    I--;
    string out;
    for(int i = N-1; i >= 0; i--){
        if(I >= dp[i][L]){
            out += '1';
            I %= dp[i][L];
            L--;
        }else{
            out += '0';
        }
    }
    cout << out << endl;
    return 0;
}


