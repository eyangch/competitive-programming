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
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    int N, K; cin >> N >> K;
    int r[N];
    for(int i = 0; i < N; i++){
        cin >> r[i];   
    }
    ll dp[N+1][K+1];
    ll dist[N][N];
    ll ans = INT_MAX;
    for(int i = 0; i < N; i++){
        fill(dist[0], dist[N-1]+N, INT_MAX);
        for(int j = 0; j < N; j++){
            ll rdist = 0;
            for(int k = 0; j+k < N; k++){
                int idx = (j+k);
                rdist += k * r[idx];
                dist[j][idx] = rdist;
            }
        }
        fill(dp[0], dp[N]+K+1, INT_MAX);
        dp[0][0] = 0;
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= K; k++){
                dp[j][k] = INT_MAX;
                for(int l = 0; l < j; l++){
                    dp[j][k] = min(dp[j][k], dp[l][k-1] + dist[l][j-1]);
                }
            }
        }
        ans = min(ans, dp[N][K]);
        for(int j = 1; j < N; j++){
            swap(r[j-1], r[j]);
        }
    }
    cout << ans << endl;
    return 0;
}


