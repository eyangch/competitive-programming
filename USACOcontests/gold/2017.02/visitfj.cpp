#include <bits/stdc++.h>
#define f first
#define s second

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

int dx[] = {1, -1, 0, 0, 3, -3, 0, 0, 2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, 0, 0, -3, 3, 1, -1, 1, -1, 2, -2, 2, -2};

int N, T;
int a[100][100];

vector<pii> get_moves(int x, int y){
    vector<pii> ans;
    for(int i = 0; i < 16; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < N && ny < N){
            ans.push_back(pii(nx, ny));
        }
    }
    return ans;
}

void dij(pii src, int (&dist)[100][100]){
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    bool vis[N][N];
    fill(dist[0], dist[N-1]+N, INT_MAX);
    fill(vis[0], vis[N-1]+N, false);
    dist[src.f][src.s] = 0;
    pq.push(make_pair(dist[src.f][src.s], src));
    while(!pq.empty()){
        pii lst = pq.top().s;
        pq.pop();
        if(vis[lst.f][lst.s]){
            continue;
        }
        vis[lst.f][lst.s] = true;
        vector<pii> go_nxt = get_moves(lst.f, lst.s);
        for(pii i : go_nxt){
            if(dist[i.f][i.s] > dist[lst.f][lst.s] + 3 * T + a[i.f][i.s]){
                dist[i.f][i.s] = dist[lst.f][lst.s] + 3 * T + a[i.f][i.s];
                pq.push(make_pair(dist[i.f][i.s], pii(i.f, i.s)));
            }
        }
    }
}

int main(){
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> T;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    int dist[100][100];
    int ans = INT_MAX;
    dij(pii(0, 0), dist);
    queue<pair<pii, int>> q;
    q.push(make_pair(pii(N-1, N-1), 0));
    while(!q.empty()){
        pii loc = q.front().f;
        int x = loc.f, y = loc.s;
        int d = q.front().s;
        q.pop();
        if(d >= 3){
            break;
        }
        ans = min(ans, dist[x][y] + T * d);
        for(int i = 0; i < 4; i++){
            if(x+dx[i] < N && y + dy[i] < N && x + dx[i] >= 0 && y + dy[i] >= 0){
                q.push(make_pair(pii(x+dx[i], y+dy[i]), d+1));
            }
        }
    }
    cout << ans << endl;
    return 0;
}


