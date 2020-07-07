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
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int N, K; cin >> N >> K;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int dp[N];
    dp[0] = a[0];
    for(int i = 1; i < N; i++){
        int mx = a[i];
        dp[i] = dp[i-1] + mx;
        for(int j = 1; j < K && i - j >= 0; j++){
            mx = max(mx, a[i-j]);
            int bef = dp[i-j-1];
            if(i - j == 0){
                 bef = 0;
            }
            dp[i] = max(dp[i], (j+1) * mx + bef);
        }
    }
    cout << dp[N-1] << endl;
    return 0;
} 

