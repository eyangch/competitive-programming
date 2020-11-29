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
int c[100];
int dp[2000001];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> X;
    fill(dp, dp+X+1, 1e7);
    for(int i = 0; i < N; i++){
        cin >> c[i];
        dp[c[i]] = 1;
    }
    for(int i = 0; i < X; i++){
        if(dp[i] < 1e7){
            for(int j = 0; j < N; j++){
                dp[i+c[j]] = min(dp[i+c[j]], dp[i]+1);
            }
        }
    }
    cout << (dp[X] == 1e7 ? -1 : dp[X]) << endl;
    return 0;
}


