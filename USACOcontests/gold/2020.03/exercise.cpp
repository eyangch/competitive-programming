#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"
#define int ll

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

int MOD;
int N;
int dp[2][10001];
bool sv[10001];

signed main(){
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> MOD;
    dp[1][0] = 1;
    int id1 = 0;
    int id2 = 1;
    int ans = 0;
    for(int i = 2; i <= N; i++){
        if(sv[i]) continue;
        for(int j = i * 2; j <= N; j += i){
            sv[j] = true;   
        }
        for(int j = 0; j <= N; j++){
            dp[id1][j] = dp[id2][j];
        }
        for(int j = i; j <= N; j *= i){
            for(int k = j; k <= N; k++){
                dp[id1][k] = (dp[id1][k] + dp[id2][k-j] * j) % MOD;
            }
        }
        id1 = !id1;
        id2 = !id2;
    }
    for(int i = 0; i <= N; i++){
        ans = (ans + dp[id2][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}


