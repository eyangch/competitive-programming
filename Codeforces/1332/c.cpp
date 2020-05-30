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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        bool been[n];
        fill(been, been + n, false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(been[i]){
                continue;
            }
            stack<int> dfs;
            been[i] = true;
            dfs.push(i);
            map<char, int> ccount;
            while(!dfs.empty()){
                int idx = dfs.top();
                dfs.pop();
                ccount[s[idx]]++;
                int idx1 = idx + k;
                int idx2 = n - idx - 1;
                if(!been[idx1] && idx1 < n){
                    been[idx1] = true;
                    dfs.push(idx1);
                }
                if(!been[idx2] && idx2 < n){
                    been[idx2] = true;
                    dfs.push(idx2);
                }
            }
            int mx = 0;
            int total = 0;
            for(auto it = ccount.begin(); it != ccount.end(); it++){
                mx = max(mx, it -> second);
                total += it -> second;
            }
            ans += total - mx;
        }
        cout << ans << endl;
    }
    return 0;
}


