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
        int a[n];
        bool pfx[n][2];
        fill(pfx[0], pfx[0] + 2, false);
        int f; cin >> f;
        a[0] = f;
        if(f > 0) pfx[0][1] = true;
        if(f < 0) pfx[0][0] = true;
        for(int i = 1; i < n; i++){
            copy(pfx[i-1], pfx[i-1] + 2, pfx[i]);
            int x; cin >> x;
            a[i] = x;
            if(x > 0){
                pfx[i][1] = true;
            }
            if(x < 0){
                pfx[i][0] = true;
            }
        }
        int tmp; cin >> tmp;
        bool good = (a[0] == tmp);
        for(int i = 1; i < n; i++){
            int x; cin >> x;
            if((x > a[i] && !pfx[i-1][1]) || (x < a[i] && !pfx[i-1][0])){
                good = false;
            }
        }
        if(good){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}


