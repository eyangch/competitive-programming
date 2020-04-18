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
        for(int i = 0; i < 9; i++){
            string s; cin >> s;
            s[3 * (i % 3) + (i / 3)] = (char)(s[3 * (i % 3) + (i / 3)] + 1);
            if(s[3 * (i % 3) + (i / 3)] > '9'){
                s[3 * (i % 3) + (i / 3)] = '1';
            }
            cout << s << endl;
        }
    }
    return 0;
}


