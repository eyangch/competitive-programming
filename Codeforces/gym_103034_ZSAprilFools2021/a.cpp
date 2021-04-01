#include <bits/stdc++.h>
 
using namespace std;
 
struct s{
    int x;
    int y;
    int d;
};
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char t[] = {'D', 'U', 'R', 'L'};
 
int N, M;
char b[1005][1005];
int dist[1000][1000];
 
int32_t main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    int ax = 0, ay = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(b[i][j] == 'P'){
                ax = i; ay = j;
            }
        }
    }
    fill(dist[0], dist[N-1]+M, -1);
    queue<s> q;
    q.push({ax, ay, 0});
    while(!q.empty()){
        int x = q.front().x, y = q.front().y, d = q.front().d;
        q.pop();
        if(x < 0) x = N-1;
        if(y < 0) y = M-1;
        if(x > N-1) x = 0;
        if(y > M-1) y = 0;
        if(b[x][y] == '#' || ~dist[x][y]){
            continue;
        }
        dist[x][y] = d;
        if(b[x][y] == 'O'){
            cout << d << endl;
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            q.push({nx, ny, d+1});
        }
    }
    cout << -1 << endl;
}
