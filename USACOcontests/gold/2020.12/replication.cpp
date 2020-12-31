#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int N, D;
string f[1000];
int mnd[1000][1000];
bool vis[1000][1000];
int mxc[1000][1000];
bool cput[1000][1000];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

priority_queue<pair<int, pii>> q1;

void bfsdijkstrathingy(){
    while(!q1.empty()){
        int x1 = q1.top().s.f, y1 = q1.top().s.s, d1 = q1.top().f;
        q1.pop();
        if(x1 < 0 || x1 >= N || y1 < 0 || y1 >= N || mxc[x1][y1] >= d1){
            continue;
        }
        mxc[x1][y1] = d1;
        cput[x1][y1] = true;
        if(d1 > 0){
            for(int i = 0; i < 4; i++){
                int nx = x1+dx[i];
                int ny = y1+dy[i];
                q1.push(make_pair(d1-1, pii(nx, ny)));
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> D;
    for(int i = 0; i < N; i++){
        cin >> f[i];
    }
    queue<pair<pii, int>> q;
    fill(mnd[0], mnd[N-1]+N, 1e6);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(f[i][j] == '#'){
                q.push(make_pair(pii(i, j), 0));
            }
        }
    }
    while(!q.empty()){
        pii sq = q.front().f;
        int d = q.front().s;
        q.pop();
        if(sq.f < 0 || sq.f >= N || sq.s < 0 || sq.s >= N || mnd[sq.f][sq.s] <= d){
            continue;   
        }
        mnd[sq.f][sq.s] = d;
        for(int i = 0; i < 4; i++){
            int nx = sq.f + dx[i];
            int ny = sq.s + dy[i];
            q.push(make_pair(pii(nx, ny), d+1));
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(f[i][j] == 'S'){
                q.push(make_pair(pii(i, j), 0));
            }
        }
    }
    fill(mxc[0], mxc[N-1]+N, -1);
    vector<pair<int, pair<int, int>>> spos;
    while(!q.empty()){
        int x = q.front().f.f, y = q.front().f.s, d = q.front().s;
        q.pop();
        int ex = (d-1)/D;
        if(x < 0 || x >= N || y < 0 || y >= N || vis[x][y] || ex >= mnd[x][y]){
            continue;
        }
        q1.push({mnd[x][y]-1, {x, y}});
        if(d/D != ex && d/D >= mnd[x][y]) continue;
        vis[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            q.push(make_pair(pii(nx, ny), d+1));
        }
    }
    bfsdijkstrathingy();
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ans += cput[i][j];
        }
    }
    cout << ans << endl;
}

