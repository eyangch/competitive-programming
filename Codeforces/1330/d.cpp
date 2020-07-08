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
    int T; cin >> T;
    while(T--){
        unsigned int d, m; cin >> d >> m;
        ll ans = 1;
        for(int i = 0; i < 30; i++){
            if(pow(2, i) > d){
                break;
            }
            ans *= min((unsigned int)pow(2, i+1) - 1, d) - pow(2, i) + 2;
            ans %= m;
        }
        if(ans == 0) ans = m;
        cout << ans - 1 << endl;
    }
    return 0;
}


