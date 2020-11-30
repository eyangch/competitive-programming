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

int MOD = 1e9+7;

int N;
int dp[130000];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int sum = (N * (N+1)) / 2;
    if(sum % 2){
        cout << 0 << endl;   
    }else{
        sum /= 2;
        dp[0] = 1;
        for(int i = 0; i < N; i++){
            for(int j = sum; j >= i; j--){
                dp[j] = (dp[j] + dp[j-i]) % MOD;
            }
        }
        cout << (dp[sum] % 2 ? (dp[sum] + MOD) / 2 : dp[sum] / 2) << endl;
    }
    return 0;
}


