#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

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

int X, Y, K, M;
bool vis[101][101][101];
int ans = 1e9;

void dfs(int a, int b, int op){
    if(op > K) return;
    if(vis[a][b][op]) return;
    ans = min(ans, abs(a+b-M));
    vis[a][b][op] = true;
    op++;
    dfs(X, b, op);
    dfs(a, Y, op);
    dfs(0, b, op);
    dfs(a, 0, op);
    if(a + b <= X){
        dfs(a+b, 0, op);
    }else{
        dfs(X, b-(X-a), op);
    }
    if(a + b <= Y){
        dfs(0, a+b, op);
    }else{
        dfs(a-(Y-b), Y, op);
    }
}

signed main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X >> Y >> K >> M;
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}


