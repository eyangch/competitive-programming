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
    int n, m; cin >> n >> m;
    int a[m];
    for(int i = 0; i < m; i++){
        cin >> a[i];
        a[i]--;   
    }
    ll total = 0;
    int hnum = 0;
    for(int i = 0; i < m; i++){
        if(a[i] < hnum){
            total += n - hnum + a[i];
        }else{
            total += a[i] - hnum;
        }
        hnum = a[i];
    }
    cout << total << endl;
    return 0;
}


