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
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    int N, K; cin >> N >> K;
    int a[N];
    for(int i = 0; i < N;i++){
        cin >> a[i];
    }
    int mseg[N][N];
    int sums[N][N];
    for(int i = 0; i < N; i++){
        mseg[i][i] = a[i];
        sums[i][i] = a[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            mseg[i][j] = max(mseg[i][j-1], a[j]);
            sums[i][j] = sums[i][j-1] + a[j];
        }
    }
    int dp[N][K+1];
    fill(dp[0], dp[N-1]+K+1, 1000000000);
    for(int i = 0; i < N; i++){
        dp[i][0] = mseg[0][i] * (i+1) - sums[0][i];
    }
    for(int i = 1; i <= K; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < j; k++){
                dp[j][i] = min(dp[j][i], dp[k][i-1] + mseg[k+1][j] * (j-k) - sums[k+1][j]);
            }
        }
    }
    cout << dp[N-1][K] << endl;
    return 0;
}


