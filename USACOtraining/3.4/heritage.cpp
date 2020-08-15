/*
ID: sireric1
LANG: C++11
TASK: heritage
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

int idx = 0;

void dfs(int N, string &a, string &b, int l, int r){
    if(l >= r){
        return;
    }
    char div = b[idx];
    int splitidx = l;
    for(; splitidx < r; splitidx++){
        if(a[splitidx] == div){
            break; 
        }
    }
    idx++;
    dfs(N, a, b, l, splitidx);
    dfs(N, a, b, splitidx+1, r);
    cout << div;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);
    string a, b; cin >> a >> b;
    int N = (int)a.length();
    dfs(N, a, b, 0, N);
    cout << endl;
    return 0;
}


