#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

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

int N, X;
int h[100000], s[100000];
int dp[2][100001];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        int a = i % 2;
        int b = !a;
        for(int j = 0; j <= X; j++){
            dp[a][j] = dp[b][j];
            if(j >= h[i]){
                dp[a][j] = max(dp[a][j], dp[b][j-h[i]] + s[i]);
                ans = max(ans, dp[a][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}


