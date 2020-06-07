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
        bool a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];   
            }
        }
        bool row[n];
        for(int i = 0; i < n; i++){
            row[i] = 0;
            for(int j = 0; j < m; j++){
                row[i] = max(row[i], a[i][j]);
            }
        }
        bool col[m];
        for(int i = 0; i < m; i++){
            col[i] = 0;
            for(int j = 0; j < n; j++){
                col[i] = max(a[j][i], col[i]);
            }
        }
        int rown = 0, coln = 0;
        for(int i = 0; i < n; i++){
            rown += row[i];
        }
        for(int i = 0; i < m; i++){
            coln += col[i];
        }
        if(min(n - rown, m - coln) % 2 == 0){
            cout << "Vivek" << endl;
        }else{
            cout << "Ashish" << endl;
        }

    }
    return 0;
}


