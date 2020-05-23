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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int s[n];
        for(int i = 0; i < n; i++){
            cin >> s[i];   
        }
        int dp[n];
        dp[0] = 1;
        for(int i = 2; i <= n; i++){
            int highest = 0;
            dp[i-1] = 0;
            for(int j = 1; j <= sqrt(i); j++){
                if(i % j == 0){
                    if(s[i-1] > s[j-1]){
                        highest = max(highest, dp[j-1]);
                    }
                    if(s[i-1] > s[i / j - 1]){
                        highest = max(highest, dp[i / j - 1]);
                    }
                }
            }
            dp[i-1] = highest + 1;
        }
        cout << *max_element(dp, dp + n) << endl;
    }
    return 0;
}


