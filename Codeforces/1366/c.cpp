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
        int matrix[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> matrix[i][j];   
            }
        }
        int diag[n+m-1][2];
        fill(diag[0], diag[n+m-2] + 2, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                diag[i+j][matrix[i][j]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < (n+m-1)/2; i++){
            ans += min(diag[i][0] + diag[n+m-2-i][0], diag[i][1] + diag[n+m-2-i][1]);
        }
        cout << ans << endl;
    }
    return 0;
}


