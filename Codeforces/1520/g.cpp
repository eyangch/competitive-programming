#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define f first
#define s second
#define int long long

using namespace std;
typedef pair<int, int> pii;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M, W, a[2000][2000], d1[2000][2000], d2[2000][2000];
vector<pii> portals;

void bfs(int sx, int sy, int (&d)[2000][2000]){
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) d[i][j] = 1e17;
    queue<pii> q;
    q.push({sx, sy});
    d[sx][sy] = 0;
    while(!q.empty()){
        int x = q.front().f, y = q.front().s;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || a[nx][ny] == -1 || d[nx][ny] < 1e17) continue;
            d[nx][ny] = d[x][y] + W;
            q.push({nx, ny});
        }
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M >> W;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            eat >> a[i][j];
            if(a[i][j] > 0) portals.push_back({i, j});
        }
    }
    bfs(0, 0, d1);
    bfs(N-1, M-1, d2);
    int mind1 = 1e17, mind2 = 1e17;
    for(pii i : portals){
        mind1 = min(mind1, a[i.f][i.s] + d1[i.f][i.s]);
        mind2 = min(mind2, a[i.f][i.s] + d2[i.f][i.s]);
    }
    int ans = min(d2[0][0], mind1 + mind2);
    moo << (ans < 1e17 ? ans : -1) << endl;
}
