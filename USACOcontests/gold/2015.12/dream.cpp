#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int N, M;
int b[1000][1000];
int dista[1000][1000][2];
bool vis[1000][1000][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool canMove(int x, int y, bool s){
    if(x < 0 || x >= N || y < 0 || y >= M || b[x][y] == 0 || (b[x][y] == 3 && !s)){
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> b[i][j];   
        }
    }
    fill(dista[0][0], dista[N-1][M-1]+2, INT_MAX);
    fill(vis[0][0], vis[N-1][M-1]+2, false);
    priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> pq; // (dist, smell), (x, y)
    dista[0][0][0] = 0;
    pq.push(make_pair(pii(0, 0), pii(0, 0)));
    while(!pq.empty()){
        pair<pii, pii> lst = pq.top();
        pq.pop();
        int x = lst.second.first, y = lst.second.second, dist = lst.first.first, smell = lst.first.second;
        if(vis[x][y][smell]){
            continue;
        }
        vis[x][y][smell] = true;
        for(int dir = 0; dir < 4; dir++){
            if(!canMove(x+dx[dir], y+dy[dir], smell)){
                continue;
            }
            int nx = x, ny = y, ndist = dist, nsmell = smell;
            while(canMove(nx+dx[dir], ny+dy[dir], nsmell)){
                ndist++;
                nx += dx[dir];
                ny += dy[dir];
                if(b[nx][ny] != 4){
                    break;
                }else{
                    nsmell = 0;
                }
            }
            if(b[nx][ny] == 2){
                nsmell = 1;
            }
            if(ndist < dista[nx][ny][nsmell]){
                dista[nx][ny][nsmell] = ndist;
                pq.push(make_pair(pii(ndist, nsmell), pii(nx, ny)));
            }else{
            }
        }
    }
    int ans = min(dista[N-1][M-1][0], dista[N-1][M-1][1]);
    if(ans == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}


