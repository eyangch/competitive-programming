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
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N; cin >> N;
        int p[2*N];
        for(int i = 0; i < 2*N; i++){
            cin >> p[i];
        }
        vi sz;
        int unum = p[0], prev = 0;
        for(int i = 1; i < 2*N; i++){
            if(p[i] > unum){
                sz.push_back(i-prev);
                prev = i;
                unum = p[i];
            }
        }
        sz.push_back(2*N-prev);
        bool dp[N+1];
        fill(dp, dp+N+1, false);
        dp[0] = true;
        for(int i = 1; i < (int)sz.size(); i++){
            for(int j = N; j >= sz[i]; j--){
                dp[j] = max(dp[j], dp[j-sz[i]]);
            }
        }
        if(dp[N]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}


