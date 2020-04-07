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
    ll n; cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];    
    }
    ll c[2];
    c[0] = c[1] = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] == 25){
            c[0]++;
        }else if(a[i] == 50){
            if(c[0] < 1){
                cout << "NO" << endl;
                return 0;
            }
            c[0]--;
            c[1]++;
        }else{
            if(c[0] >= 1 && c[1] >= 1){
                c[0]--;
                c[1]--;
                continue;
            }else if(c[0] >= 3 && c[1] < 1){
                c[0] -= 3;
            }else{
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}


