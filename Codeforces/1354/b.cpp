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
        string s; cin >> s;
        int n = (int)s.length();
        int ans = 0;
        map<char, int> found1;
        int l = 0;
        int r = 0;
        for(; r < n && (int)found1.size() < 3; r++){
            found1[s[r]]++;
            while(found1[s[l]] > 1){
                found1[s[l]]--;
                l++;
            }
        }
        if((int)found1.size() < 3){
            cout << 0 << endl;
            continue;
        }
        ans = r - l;
        while(r <= n){
            while(found1[s[l]] > 1){
                found1[s[l]]--;
                l++;
            }
            found1[s[r]]++;
            ans = min(ans, r - l);
            r++;
        }
        cout << ans << endl;
    }
    return 0;
}


