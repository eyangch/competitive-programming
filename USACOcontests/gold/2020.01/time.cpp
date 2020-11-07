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

int N, M, C, m[1000], dp[1050][1050];
vi graph[1000];

int main(){
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> M >> C;
    for(int i = 0; i < N; i++){
        cin >> m[i];
    }
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
    }
    fill(dp[0], dp[1049]+1050, -1);
    dp[0][0] = 0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < N; j++){
            if(dp[i][j] >= 0){
                for(int k : graph[j]){
                    dp[i+1][k] = max(dp[i+1][k], dp[i][j] + m[k]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 1000; i++){
        ans = max(ans, dp[i][0] - C * i * i);
    }
    cout << ans << endl;
    return 0;
}


