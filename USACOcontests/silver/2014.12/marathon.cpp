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

int dist(pii a, pii b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    int N, K; cin >> N >> K;
    pii ckpt[N];
    for(int i = 0; i < N; i++){
        cin >> ckpt[i].first >> ckpt[i].second;
    }
    int dp[N][K+1];
    fill(dp[0], dp[N-1]+K+1, 2000000);
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= min(i, K); j++){
            for(int k = i+1; k < N; k++){
                if(k-i-1+j > K){
                    break;
                }
                dp[k][k-i-1+j] = min(dp[k][k-i-1+j], dp[i][j] + dist(ckpt[i], ckpt[k]));
            }
        }
    }
    cout << dp[N-1][K] << endl;
    return 0;
}


