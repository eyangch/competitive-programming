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
int x[100];
bool dp[100001];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    dp[0] = true;
    for(int i = 0; i < N; i++){
        cin >> x[i];
        for(int j = 100000; j >= 0; j--){
            if(j < x[i]) break;
            dp[j] = max(dp[j], dp[j-x[i]]);
        }
    }
    vi ans;
    for(int i = 1; i < 100001; i++){
        if(dp[i]){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


