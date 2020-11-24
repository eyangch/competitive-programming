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
int a[1000], b[1000];
int dp[1000][1000];
int mx[1000][1000];

signed main(){
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i > 0 && j > 0){
                dp[i][j] = mx[i-1][j-1];
            }
            if(i > 0){
                mx[i][j] = max(mx[i][j], mx[i-1][j]);
            }
            if(j > 0){
                mx[i][j] = max(mx[i][j], mx[i][j-1]);
            }
            dp[i][j] += (abs(a[i] - b[j]) <= 4);
            mx[i][j] = max(mx[i][j], dp[i][j]);
        }
    }
    cout << mx[N-1][N-1] << endl;
    return 0;
}


