#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int X, Y;
int h[500][500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool bad = false;
int cpt = 0;
bool vis[500][500];

void ffill(int x, int y){
    if(vis[x][y]) return;
    vis[x][y] = true;
    cpt++;
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
        if(h[nx][ny] < h[x][y]){
            bad = true;
        }
        if(h[nx][ny] == h[x][y]){
            ffill(nx, ny);
        }
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> X >> Y;
    swap(X, Y);
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            eat >> h[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            if(vis[i][j]) continue;
            bad = false;
            cpt = 0;
            ffill(i, j);
            if(!bad) ans += cpt;
        }
    }
    moo << ans << endl;
}
