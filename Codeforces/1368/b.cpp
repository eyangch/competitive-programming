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
    ll k; cin >> k;
    ll n = 1;
    ll ans[10];
    string out = "codeforces";
    fill(ans, ans+10, 1);
    for(int i = 2; i < 100; i++){
        if(n >= k){
            break;
        }
        for(int j = 0; j < 10; j++){
            if(n >= k){
                break;
            }
            n /= i-1;
            n *= i;
            ans[j] = i;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < ans[i]; j++){
            cout << out[i];
        }
    }
    cout << endl;
    return 0;
}


