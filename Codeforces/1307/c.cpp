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
    string s; cin >> s;
    int n = (int)s.length();
    map<char, ll> ct;
    for(int i = 0; i < n; i++){
        ct[s[i]]++;   
    }
    ll m = 0;
    for(char i = 'a'; i <= 'z'; i++){
        m = max(m, ct[i]);
        m = max(m, ct[i] * (ct[i] - 1) / 2);
    }
    for(char i = 'a'; i <= 'z'; i++){
        for(char j = 'a'; j <= 'z'; j++){
            if(i == j){
                continue;
            }
            int cnt = 0;
            ll total = 0;
            for(int k = 0; k < n; k++){
                if(s[k] == i){
                    cnt++;
                }
                if(s[k] == j){
                    total += cnt;
                }
            }
            m = max(m, total);
        }
    }
    cout << m << endl;
    return 0;
}


