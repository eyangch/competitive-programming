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
        int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
        if((a1 + a2 == b2 && a1+a2 == b1) || (a1+b2 == a2 && a1+b2 == b1) || (a2+b1 == a1 && a2+b1 == b2) || (b1+b2 == a1 && b1+b2 == a2)){
            cout << "YES" << endl;   
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}


