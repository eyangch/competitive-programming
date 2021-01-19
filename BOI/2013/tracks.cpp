#include <bits/stdc++.h>

using namespace std;

struct s{
    int x, y, d;
};
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int H, W;
string m[4000];
bool vis[4000][4000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> m[i];
    }
    deque<s> q;
    q.push_back({0, 0, 1});
    int ans = 0;
    while(!q.empty()){
        s cur = q.front();
        q.pop_front();
        int x = cur.x, y = cur.y, d = cur.d;
        if(vis[x][y]) continue;
        vis[x][y] = true;
        ans = max(ans, d);
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= H || ny >= W || m[nx][ny] == '.') continue;
            if(m[x][y] != m[nx][ny]){
                q.push_back({nx, ny, d+1});
            }else{
                q.push_front({nx, ny, d});
            }
        }
    }
    cout << ans << endl;
}
