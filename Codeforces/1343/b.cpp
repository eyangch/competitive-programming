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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n % 4 != 0){
            cout << "NO" << endl;
            continue;    
        }
        cout << "YES" << endl;
        for(int i = 0; i < n / 2; i++){
            cout << (i + 1) * 2 << " ";
        }
        for(int i = 0; i < n / 2 - 1; i++){
            cout << i * 2 + 1 << " ";
        }
        cout << (n - 1) + (n / 2) << endl;
    }
    return 0;
}


