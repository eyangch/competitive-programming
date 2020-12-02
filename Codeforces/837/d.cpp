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

int N, K;
int a[200];
int dp[2][5200][200];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> K;
    fill(dp[0][0], dp[1][5199]+200, -1e9);
    int mxidx = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        int two = 0;
        while(a[i] % 2 == 0){
            two++;
            a[i] /= 2;
        }
        int five = 0;
        while(a[i] % 5 == 0){
            five++;
            a[i] /= 5;
        }
        int m1 = i % 2;
        int m2 = !m1;
        mxidx += five;
        for(int j = 0; j <= mxidx; j++){
            for(int k = 0; k <= min(K-1, i); k++){
                dp[m1][j][k] = dp[m2][j][k];
            }
        }
        dp[m1][five][0] = max(dp[m2][five][0], two);
        for(int j = five; j <= mxidx; j++){
            for(int k = 1; k <= min(K-1, i); k++){
                dp[m1][j][k] = max(dp[m2][j][k], dp[m2][j-five][k-1] + two);
            }
            for(int k = 0; k <= min(K-1, i); k++){
                ans = max(ans, min(dp[m1][j][k], j));
            }
        }
    }
    cout << ans << endl;
    return 0;
}


