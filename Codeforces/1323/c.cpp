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
    int n; cin >> n;
    string s; cin >> s;
    int tcnt = 0;
    for(int i = 0; i < n; i++){
        tcnt += (s[i] == '(' ? 1 : -1);
    }
    if(tcnt != 0){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        tcnt += (s[i] == '(' ? 1 : -1);
        int idx = i;
        while(tcnt < 0){
            idx++;
            tcnt += (s[idx] == '(' ? 1 : -1); 
        }
        if(idx != i){
            ans += idx - i + 1;
        }
        i = idx;
    }
    cout << ans << endl;
    return 0;
}


