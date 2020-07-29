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

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

struct state{
    int x1;
    int y1;
    int x2;
    int y2;
    int dir;
    int dist;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
    int N; cin >> N;
    string barn[N];
    for(int i = 0; i < N; i++) cin >> barn[i];
    int dp[N][N][N][N][4];
    fill(dp[0][0][0][0], dp[N-1][N-1][N-1][N-1]+4, INT_MAX);
    queue<state> bfs;
    state nxt = {N-1, 0, N-1, 0, 0, 0};
    bfs.push(nxt);
    while(!bfs.empty()){
        state c = bfs.front();
        bfs.pop();
        if(dp[c.x1][c.y1][c.x2][c.y2][c.dir] != INT_MAX) continue;
        //cout << c.x1 << " " << c.y1 << " " << c.x2 << " " << c.y2 << " " << c.dir << " " << c.dist << endl;
        dp[c.x1][c.y1][c.x2][c.y2][c.dir] = c.dist;
        // forward:
        nxt = {c.x1 + dx[c.dir], c.y1 + dy[c.dir], c.x2 + dx[(c.dir+1)%4], c.y2 + dy[(c.dir+1)%4], c.dir, c.dist+1};
        if((c.x1 == 0 && c.y1 == N-1) || nxt.x1 < 0 || nxt.y1 < 0 || nxt.x1 >= N || nxt.y1 >= N || barn[nxt.x1][nxt.y1] == 'H'){
            nxt.x1 = c.x1;
            nxt.y1 = c.y1;
        }
        if((c.x2 == 0 && c.y2 == N-1) || nxt.x2 < 0 || nxt.y2 < 0 || nxt.x2 >= N || nxt.y2 >= N || barn[nxt.x2][nxt.y2] == 'H'){
            nxt.x2 = c.x2;
            nxt.y2 = c.y2;
        }
        bfs.push(nxt);
        // right:
        nxt = {c.x1, c.y1, c.x2, c.y2, (c.dir+1)%4, c.dist+1};
        bfs.push(nxt);
        // left:
        nxt = {c.x1, c.y1, c.x2, c.y2, (c.dir+3)%4, c.dist+1};
        bfs.push(nxt);
    }
    int ans = INT_MAX;
    for(int i = 0; i < 4; i++){
        ans = min(ans, dp[0][N-1][0][N-1][i]);
        //cout << dp[0][N-1][0][N-1][i] << endl;
    }
    cout << ans << endl;
    return 0;
}


