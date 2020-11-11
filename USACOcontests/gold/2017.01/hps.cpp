#include <bits/stdc++.h>
#define f first
#define s second

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

int N, K;
int dp[100000][22][3];
int fj[100000];
int mp[128];

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    mp['H'] = 0;
    mp['P'] = 1;
    mp['S'] = 2;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        char x; cin >> x;
        fj[i] = (mp[x]+1)%3;
    }
    fill(dp[0][0], dp[99999][21]+3, -1);
    dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 0;
    dp[0][0][fj[0]] = 1;
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j <= K; j++){
            for(int k = 0; k < 3; k++){
                if(dp[i][j][k] >= 0){
                    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + (fj[i+1] == k));
                    for(int l = 0; l < 3; l++){
                        if(k == l) continue;
                        dp[i+1][j+1][l] = max(dp[i+1][j+1][l], dp[i][j][k] + (fj[i+1] == l));
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= K; i++){
        for(int j = 0; j < 3; j++){
            ans = max(ans, dp[N-1][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}


