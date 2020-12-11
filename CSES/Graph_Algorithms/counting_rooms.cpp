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

void setIO(string s){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(s != ""){
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
string b[1000];
int vis[1000][1000];

void dfs(int x, int y){
    if(vis[x][y] || b[x][y] == '#'){
        return;   
    }
    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M){
            continue;
        }
        dfs(nx, ny);
    }
}

signed main(){
    setIO("");
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!vis[i][j] && b[i][j] == '.'){
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}


