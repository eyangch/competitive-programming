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
    int v; cin >> v;
    int c[9];
    for(int i = 0; i < 9; i++){
        cin >> c[i];   
    }
    int midx1 = 0;
    int mval1 = 100000000;
    for(int i = 0; i < 9; i++){
        if(c[i] <= mval1){
            mval1 = c[i];
            midx1 = i;
        }
    }
    int n = v / mval1;
    int r = v % mval1;
    string ans;
    for(int i = 0; i < v/mval1; i++){
        ans += (char)(midx1 + 49);
    }
    for(int i = 0; i < n; i++){
        r += mval1;
        for(int j = 9; j >= 1; j--){
            if(c[j-1] <= r){
                ans[i] = (char)(j + 48);
                r -= c[j-1];
            }
        }
    }
    if(ans.length() == 0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}


