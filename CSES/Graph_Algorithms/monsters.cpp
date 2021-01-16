#include <bits/stdc++.h>

using namespace std;

struct s{
    int x, y;
    unsigned int d;
};

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
string rev = "LRDU";

int N, M;
string g[1000];
unsigned int md[1000][1000], di[1000][1000];

int32_t main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> g[i];
    }
    queue<s> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(g[i][j] == 'M'){
                q.push({i, j, 0});
            }
        }
    }
    fill(md[0], md[N-1]+M, -1);
    while(!q.empty()){
        s cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y;
        unsigned int d = cur.d;
        if(x < 0 || y < 0 || x >= N || y >= M || g[x][y] == '#' || ~md[x][y]) continue;
        md[x][y] = d;
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            q.push({nx, ny, d+1});
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(g[i][j] == 'A'){
                q.push({i, j, 0});
            }
        }
    }
    fill(di[0], di[N-1]+M, -1);
    while(!q.empty()){
        s cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y;
        unsigned int d = cur.d;
        if(g[x][y] == '#' || ~di[x][y] || d >= md[x][y]) continue;
        di[x][y] = d;
        if(x == 0 || y == 0 || x == N-1 || y == M-1){
            cout << "YES" << endl << d << endl;
            stack<char> ans;
            while(g[x][y] != 'A'){
                for(int i = 0; i < 4; i++){
                    int nx = x+dx[i], ny = y+dy[i];
                    if(di[nx][ny] == di[x][y]-1){
                        ans.push(rev[i]);
                        x = nx, y = ny;
                        break;
                    }
                }
            }
            while(!ans.empty()){
                cout << ans.top();
                ans.pop();
            }
            cout << endl;
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            q.push({nx, ny, d+1});
        }
    }
    cout << "NO" << endl;
}
