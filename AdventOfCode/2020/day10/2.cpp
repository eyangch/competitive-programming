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
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int dp[100];

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    int nxt;
    vi a;
    while(cin >> nxt){
        a.push_back(nxt);  
    }
    a.push_back(0);
    sort(a.begin(), a.end());
    a.push_back(a[a.size()-1] + 3);
    dp[0] = 1;
    for(int i = 1; i < (int)a.size(); i++){
        for(int j = i-1; j >= 0 && a[i] - a[j] <= 3; j--){
            dp[i] += dp[j];
        }
    }
    cout << dp[a.size()-1] << endl;
    return 0;
}




