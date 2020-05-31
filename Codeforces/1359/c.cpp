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

double calc(ll &n, ll &h, ll &c, ll x){
    return abs((double)n - (double)(x * h + (x-1) * c) / (double)(2 * x - 1)); 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        ll h, c, n; cin >> h >> c >> n;
        if(n <= (h + c) / 2){
            cout << 2 << endl;
            continue;
        }
        ll x = (c - n) / (h + c - 2 * n);
        if((c - n) % (h + c - 2 * n) == 0){
            cout << (x - 1) * 2 + 1 << endl;   
        }else if(calc(n, h, c, x) > calc(n, h, c, x + 1)){
            cout << x * 2 + 1 << endl;
        }else{
            cout << (x - 1) * 2 + 1 << endl;
        }
    }
    return 0;
}


