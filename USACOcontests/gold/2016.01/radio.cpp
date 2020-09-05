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

int dx[128], dy[128];

int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    dx['N'] = dx['S'] = dy['W'] = dy['E'] = 0;
    dy['N'] = dx['E'] = 1;
    dy['S'] = dx['W'] = -1;
    int N, M; cin >> N >> M;
    int fcx[N+1], fcy[N+1], bcx[M+1], bcy[M+1];
    cin >> fcx[0] >> fcy[0] >> bcx[0] >> bcy[0];
    string fp, bp; cin >> fp >> bp;
    for(int i = 1; i <= N; i++){
        fcx[i] = fcx[i-1] + dx[fp[i-1]];
        fcy[i] = fcy[i-1] + dy[fp[i-1]];
    }
    for(int i = 1; i <= M; i++){
        bcx[i] = bcx[i-1] + dx[bp[i-1]];
        bcy[i] = bcy[i-1] + dy[bp[i-1]];
    }
    fill(dp[0], dp[N]+M+1, 1e9); 
    dp[0][0] = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            int dist = pow(fcx[i]-bcx[j],2)+pow(fcy[i]-bcy[j],2);
            if(i > 0){
                dp[i][j] = min(dp[i][j], dist + dp[i-1][j]);
            }
            if(j > 0){
                dp[i][j] = min(dp[i][j], dist + dp[i][j-1]);
            }
            if(i > 0 && j > 0){
                dp[i][j] = min(dp[i][j], dist + dp[i-1][j-1]);
            }
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}


