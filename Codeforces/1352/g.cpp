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
        if(n < 4){
            cout << -1 << endl;
            continue;
        }
        int c = 2;
        for(; c <= n; c+=2){
            cout << c << " ";
        }
        c -= 2 + 3;
        for(; c > 1; c-= 4){
            cout << c << " ";
        }
        cout << 1 << " ";
        if(c == 1){
            c += 2;
        }else{
            c = 5;
        }
        for(; c <= n; c+=4){
            cout << c << " ";
        }
        if(n % 2 == 1){
            cout << n;
        }
        cout << endl;
    }
    return 0;
}


