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
        int a, b, c, d; cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        x += b-a;
        y += d-c;
        int good = true;
        if(x2 == x1 && a + b > 0){
            good = false;
        }
        if(y2 == y1 && c + d > 0){
            good = false;
        }
        if(good && x >= x1 && x <= x2 && y >= y1 && y <= y2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    } 
    return 0;
}


