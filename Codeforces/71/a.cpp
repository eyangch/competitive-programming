#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> v){for(T i : v) os << i << " ";}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << " ";}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl;}

int main(){
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        if(s.length() <= 10){
            cout << s << endl;
        }else{
            cout << s[0] << s.length() - 2 << s[s.length()-1] << endl;
        }
    }
    return 0;
}

