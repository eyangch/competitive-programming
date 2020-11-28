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

int N;
int a[100];
int dp[100][100];

signed main(){
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        dp[0][i] = (a[i] != i);
        if(i > 0){
            dp[0][i] = 1e9;
        }
    }
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j++){
            dp[i][j] = 1e9;
            for(int k = j; k >= i; k--){
                int add = (a[j] != 0);
                for(int l = k; l < j; l++){
                    add += (a[l] != l-k+1);
                }
                dp[i][j] = min(dp[i][j], dp[i-1][k-1] + add);
            }
        }
    }
    for(int i = 0; i < N; i++){
        int ans = 1e9;
        for(int j = N-1; j >= i; j--){
            int add = 0;
            for(int k = j+1; k < N; k++){
                add += (a[k] != k-j);
            }
            ans = min(ans, dp[i][j] + add);
        }
        cout << ans << endl;
    }
    return 0;
}


