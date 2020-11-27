#include <bits/stdc++.h>
#define f first
#define s second

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

int N;
string s;
set<string> ans;

void dfs(int pos, string x){
    if((int)x.length() == N){
        ans.insert(x);
        return;
    }
    for(int i = 0; i < N; i++){
        if((pos&(1<<i))){
            continue;
        }
        int tmpi = pos | (1<<i);
        string tmp = x + s[i];
        dfs(tmpi, tmp);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    N = (int)s.length();
    dfs(0, "");
    cout << ans.size() << endl;
    for(string i : ans){
        cout << i << endl;
    }
    return 0;
}


