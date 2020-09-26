#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll dp[100000][26];
ll mdp[100000];
ll sum[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    ll N, M, K; cin >> N >> M >> K;
    string Sstr; cin >> Sstr;
    ll S[N];
    for(ll i = 0; i < N; i++){
        S[i] = Sstr[i] - 'a';
    }
    ll dist[M][M];
    for(ll i = 0; i < M; i++){
        for(ll j = 0; j < M; j++){
            cin >> dist[i][j];
        }
    }
    for(ll k = 0; k < M; k++){
        for(ll i = 0; i < M; i++){
            for(ll j = 0; j < M; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(ll i = 0; i < M; i++){
        for(ll j = 0; j < K; j++){
            dp[j][i] = 1e9;
            sum[i] += dist[S[j]][i];
            mdp[j] = 1e9;
        }
    }
    fill(mdp, mdp+N, 1e9);
    for(ll i = 0; i < M; i++){
        dp[K-1][i] = sum[i];
        mdp[K-1] = min(dp[K-1][i], mdp[K-1]);
    }
    for(ll i = K; i < N; i++){
        for(ll j = 0; j < M; j++){
            sum[j] += dist[S[i]][j]-dist[S[i-K]][j];
            dp[i][j] = min(dp[i-1][j]+dist[S[i]][j], mdp[i-K]+sum[j]);
            mdp[i] = min(mdp[i], dp[i][j]);
        }
    }
    cout << mdp[N-1] << endl;
    return 0;
}


