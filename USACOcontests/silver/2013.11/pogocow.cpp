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

int dp[1000][1000]; // dp[curr][prev]

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pogocow.in", "r", stdin);
    freopen("pogocow.out", "w", stdout);
    int N; cin >> N;
    pii c[N];
    for(int i = 0; i < N; i++){
        cin >> c[i].first >> c[i].second;   
    }
    sort(c, c+N);
    fill(dp[0], dp[N-1]+N, 0);
    int ans = 0;
    for(int i = 0; i < N; i++){
        dp[i][i] = c[i].second;
        ans = max(ans, dp[i][i]);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            int cdiff = c[i].first - c[j].first;
            for(int k = j; k >= 0 && c[j].first - c[k].first <= cdiff; k--){
                dp[i][j] = max(dp[i][j], dp[j][k]+c[i].second);
            }
            ans = max(ans, dp[i][j]);
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    for(int i = N-1; i >= 0; i--){
        for(int j = N-1; j > i; j--){
            int cdiff = c[j].first - c[i].first;
            for(int k = j; k < N && c[k].first - c[j].first <= cdiff; k++){
                dp[i][j] = max(dp[i][j], dp[j][k]+c[i].second);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}


