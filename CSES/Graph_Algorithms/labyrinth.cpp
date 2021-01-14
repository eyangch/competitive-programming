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

void print(int x){
    int dv = 1000000;
    while(true){
        if(x/dv > 0) break;
        dv /= 10;
    }
    while(dv > 0){
        int v = x/dv;
        x %= dv;
        dv /= 10;
        putchar_unlocked(v + '0');
    }
    putchar_unlocked('\n');
}

int getN(){
    char x;
    int ret = 0;
    while((x = getchar_unlocked()) < '0'){}
    while(x >= '0'){
        ret *= 10;
        ret += x-'0';
        x = getchar_unlocked();
    }
    return ret;
}

int32_t main(){
    N = getN();
    M = getN();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char x;
            while((x = getchar_unlocked()) <= ' '){}
            b[i][j] = x;
        }
    }
    int ax = 0, ay = 0, bx = 0, by = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(b[i][j] == 'A'){
                ax = i; ay = j;
            }
            if(b[i][j] == 'B'){
                bx = i; by = j;
            }
        }
    }
    fill(dist[0], dist[N-1]+M, -1);
    queue<s> q;
    q.push({ax, ay, 0});
    while(!q.empty()){
        int x = q.front().x, y = q.front().y, d = q.front().d;
        q.pop();
        if(x < 0 || x >= N || y < 0 || y >= M || b[x][y] == '#' || ~dist[x][y]){
            continue;
        }
        dist[x][y] = d;
        if(x == bx && y == by){
            stack<char> ans;
            putchar_unlocked('Y');
            putchar_unlocked('E');
            putchar_unlocked('S');
            putchar_unlocked('\n');
            print(d);
            while(x != ax || y != ay){
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M || b[nx][ny] == '#' || dist[nx][ny] != dist[x][y] - 1){
                        continue;
                    }
                    ans.push(t[i]);
                    x = nx, y = ny;
                    break;
                }
            }
            while(!ans.empty()){
                putchar_unlocked(ans.top()), ans.pop();
            }
            putchar_unlocked('\n');
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            q.push({nx, ny, d+1});
        }
    }
    putchar_unlocked('N');
    putchar_unlocked('O');
    putchar_unlocked('\n');
}
