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
        int n, m; cin >> n >> m;
        string a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];   
        }
        unordered_set<char> possible[m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                possible[j].insert(a[i][j]);
            }
        }
        string ans = "-1";
        for(int i = 0; i < m; i++){
            string comp = a[0];
            for(char c : possible[i]){
                comp[i] = c;
                bool good = true;
                for(int j = 1; j < n; j++){
                    int diff = 0;
                    for(int k = 0; k < m; k++){
                        if(comp[k] != a[j][k]){
                            diff++;
                        }
                    }
                    if(diff > 1){
                        good = false;
                        break;
                    }
                }
                if(good){
                    ans = comp;
                    goto finish;
                }
            }
        }
        finish:
        cout << ans << endl;
    }
    return 0;
}


