/*
ID: sireric1
LANG: C++11
TASK: stamps
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

int dp[10000 * 205];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    int N, K; cin >> K >> N;
    int s[N];
    fill(dp, dp+(10000 * K), K+1);
    for(int i = 0; i < N; i++){
        cin >> s[i];   
        dp[s[i]] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= 10000 * K; i++){
        if(dp[i] == K+1){
            ans = i-1;
            break;
        }
        for(int j = 0; j < N; j++){
            dp[i+s[j]] = min(dp[i+s[j]], dp[i]+1);
        }
    }
    cout << ans << endl;
    return 0;
}


