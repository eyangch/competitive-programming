#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    int H, W; eat >> H >> W;
    string b[5];
    for(int i = 0; i < H; i++) eat >> b[i];
    int x = 0, y = 0, ans = 0;
    while(x < H){
        ans += (b[x][y] == '*');
        int nx = H, ny = W;
        for(int i = x; i < H; i++){
            for(int j = y; j < W; j++){
                if(i == x && j == y) continue;
                if(b[i][j] == '*'){
                    if(i-x + j-y < nx-x + ny-y){
                        nx = i, ny = j;
                    }
                }
            }
        }
        x = nx, y = ny;
    }
    moo << ans << endl;
}
