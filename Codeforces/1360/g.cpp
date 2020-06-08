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
        int n, m, a, b; cin >> n >> m >> a >> b;
        if(m * b != n * a){
            cout << "NO" << endl;
            continue;    
        }   
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            string row = string(m, '0');
            for(int j = 0; j < a; j++){
                row[(i*a+j) % m] = '1';
            }
            cout << row << endl;
        }
    }
    return 0;
}


