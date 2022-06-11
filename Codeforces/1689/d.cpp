#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, d[1000][1000];
string b[1000];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dist(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++){
            eat >> b[i];
        }
        for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) d[i][j] = -1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(b[i][j] == 'W') continue;
                d[0][0] = max(d[0][0], dist(0, 0, i, j));
                d[N-1][0] = max(d[N-1][0], dist(N-1, 0, i, j));
                d[0][M-1] = max(d[0][M-1], dist(0, M-1, i, j));
                d[N-1][M-1] = max(d[N-1][M-1], dist(N-1, M-1, i, j));
            }
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({d[0][0], {0, 0}});
        pq.push({d[N-1][0], {N-1, 0}});
        pq.push({d[0][M-1], {0, M-1}});
        pq.push({d[N-1][M-1], {N-1, M-1}});
        while(!pq.empty()){
            int cd = pq.top().first;
            int cx = pq.top().second.first;
            int cy = pq.top().second.second;
            pq.pop();
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(d[nx][ny] != -1) continue;
                d[nx][ny] = cd - 1;
                pq.push({cd-1, {nx, ny}});
            }
        }
        int best = 9999999;
        int bx = 0, by = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(d[i][j] < best){
                    best = d[i][j];
                    bx = i;
                    by = j;
                }
            }
        }
        moo << bx+1 << ' ' << by+1 << endl;
    }
}
