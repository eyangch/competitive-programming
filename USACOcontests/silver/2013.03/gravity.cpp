#include <bits/stdc++.h>

using namespace std;

struct state{int x;int y;bool g;int d;};

int N, M;
string b[500];
unsigned int di[500][500][2];

int32_t main(){
    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    pair<int, int> start, finish;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(b[i][j] == 'C'){
                start = {i, j};
            }if(b[i][j] == 'D'){
                finish = {i, j};
            }
        }
    }
    deque<state> q;
    q.push_back({start.first, start.second, 0, 0});
    fill(di[0][0], di[N-1][M-1]+2, -1);
    while(!q.empty()){
        state s =  q.front();
        int x = s.x, y = s.y, g = s.g, d = s.d;
        q.pop_front();
        if(x < 0 || y < 0 || x >= N || y >= M || b[x][y] == '#') continue;
        if(!(~di[x][y][g])){
            di[x][y][g] = d;
        }else{
            continue;
        }
        int dx = 1;
        if(g) dx = -1;
        if(x + dx < 0 || x + dx >= N){
            continue;
        }
        if(b[x+dx][y] != '#'){
            q.push_front({x+dx, y, g, d});
        }else{
            q.push_front({x, y+1, g, d});
            q.push_front({x, y-1, g, d});
            q.push_back({x, y, !g, d+1});
        }
    }
    int ans = min(di[finish.first][finish.second][0], di[finish.first][finish.second][1]);
    cout << (ans > 1e9 ? -1 : ans) << endl;
}
