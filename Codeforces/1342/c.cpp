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
        int a, b, q; cin >> a >> b >> q;
        bool eq[a * b];
        int total = 0;
        for(int i = 0; i < a * b; i++){
            if((i % a) % b == (i % b) % a){
                eq[i] = false;
            }else{
                eq[i] = true;
                total++;
            }
        }
        for(int qn = 0; qn < q; qn++){
            ll l, r; cin >> l >> r;
            ll ans = ((r - l + 1) / (a * b)) * total;
            l %= (a * b);
            r %= (a * b);
            for(int i = l; i != r + 1; i++){
                if(i >= a * b){
                    i = 0;
                }
                ans += eq[i]; 
            }
            cout << ans << " ";
        }cout << endl;
    }
    return 0;
}


