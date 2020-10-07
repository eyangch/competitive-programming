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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cout << "Case #" << tc << ": ";
        int N, K, P; cin >> N >> K >> P;   
        int plt[N][K];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < K; j++){
                cin >> plt[i][j];
                if(j > 0){
                    plt[i][j] += plt[i][j-1];
                }
            }
        }
        int dp[N+1][P+1];
        for(int i = 0; i <= P; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= N; i++){
            for(int j = 0; j <= P; j++){
                dp[i][j] = dp[i-1][j];
                for(int k = 0; k < K; k++){
                    if(j - k - 1 < 0) break;
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k-1] + plt[i-1][k]);
                }
            }
        }
        cout << dp[N][P] << endl;
    }
    return 0;
}


