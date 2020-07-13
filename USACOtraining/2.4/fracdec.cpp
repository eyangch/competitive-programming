/*
ID: sireric1
LANG: C++11
TASK: fracdec
*/

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
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    int N, D; cin >> N >> D;
    int rm[D];
    fill(rm, rm+D, -1);
    int whn = N/D;
    N %= D;
    string ans = to_string(whn);
    ans += '.';
    string dec;
    for(int i = 0; N % D != 0 && rm[N % D] == -1; i++){
        rm[N] = i;
        N *= 10;
        dec += (char)((N / D) + 48);
        N %= D;
    }
    for(int i = 0; i < (int)dec.length(); i++){
        if(rm[N] == i) ans += '(';
        ans += dec[i];
    }
    if(rm[N] != -1) ans += ')';
    if((int)dec.length() == 0){
        ans += '0';
    }
    for(int i = 0; i < (int)ans.length(); i++){
        if(i != 0 && i % 76 == 0) cout << endl;
        cout << ans[i];
    }
    cout << endl;
    return 0;
}


