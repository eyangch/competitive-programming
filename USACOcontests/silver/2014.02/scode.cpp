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

int works(string s, int s1, int s2, int s3, int s4){
    if(s4 - s3 >= s2 - s1){
        return 0;
    }
    string cstr = s.substr(s1, s2-s1+1);
    string compstr = s.substr(s3, s4-s3+1);
    string cstr1 = cstr.substr(0, compstr.length());
    string cstr2 = cstr.substr(cstr.length() - compstr.length() , string::npos);
    int ret = 0;
    ret += (cstr1 == compstr);
    ret += (cstr2 == compstr);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("scode.in", "r", stdin);
    freopen("scode.out", "w", stdout);
    string s; cin >> s;
    int N = (int)s.length();
    map<pii, ll> sub;
    sub[pii(0, N-1)]++;
    ll ans = 0;
    for(int i = N-2; i > 0; i--){
        for(int j = 0; j + i < N; j++){
            for(int k = 1; i + j + k < N; k++){
                int wk = works(s, j, j+i, j+i+1, j+i+k);
                if(sub.find(pii(j, j+i+k)) == sub.end() || !wk){
                    continue;
                }
                sub[pii(j, j+i)] += wk * sub[pii(j, j+i+k)];
                sub[pii(j, j+i)] %= 2014;
            }
            for(int k = 0; k < j; k++){
                int wk = works(s, j, j+i, k, j-1);
                if(sub.find(pii(k, j+i)) == sub.end() || !wk){
                    continue;
                }
                sub[pii(j, j+i)] += wk * sub[pii(k, j+i)];
                sub[pii(j, j+i)] %= 2014;
            }
            ans += sub[pii(j, j+i)];
            ans %= 2014;
        }
    }
    cout << ans << endl;
    return 0;
}


