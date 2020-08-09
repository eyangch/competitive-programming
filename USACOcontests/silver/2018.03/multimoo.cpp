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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N;
int b[250][250];
int ids[250][250];
bool vis2[250][250];
set<int> visg;
set<pair<int, pii>> adone;
vi graph[62500];
vi idnum;
vi idval;

int ffill(int x, int y, int id){
    ids[x][y] = id;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || b[x][y] != b[nx][ny] || ids[nx][ny] != -1) continue;
        ret += ffill(nx, ny, id);
    }
    return ret;
}

void ffill2(int x, int y, int id){
    if(ids[x][y] != id){
        graph[id].push_back(ids[x][y]);
    }else{
        if(vis2[x][y]) return;
        vis2[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            ffill2(nx, ny, id);
        }
    }
}

int dfs(int id, int a, int b){
    if(visg.find(id) != visg.end() || adone.find(make_pair(id, pii(a, b))) != adone.end()) return 0;
    adone.insert(make_pair(id, pii(a, b)));
    visg.insert(id);
    int ret = idval[id];
    for(int i : graph[id]){
        if(idnum[i] == a || idnum[i] == b){
            ret += dfs(i, a, b);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> b[i][j];
        }
    }
    fill(ids[0], ids[N-1]+N, -1);
    int idcnt = 0;
    for(int i = 0; i < N; i++){
        for(int j= 0; j < N; j++){
            if(ids[i][j] != -1) continue;
            idnum.push_back(b[i][j]);
            idval.push_back(ffill(i, j, idcnt));
            idcnt++;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(vis2[i][j]) continue;
            ffill2(i, j, ids[i][j]); 
        }
    }
    for(int i = 0; i < idcnt; i++){
        sort(graph[i].begin(), graph[i].end());
        graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
    }
    int ans = 0;
    int ans2 = 0;
    for(int i : idval){
        ans = max(ans, i);
    }
    for(int i = 0; i < idcnt; i++){
        for(int j : graph[i]){
            if(adone.find(make_pair(i, pii(idnum[i], idnum[j]))) != adone.end()) continue;
            visg.clear();
            int x = dfs(i, idnum[i], idnum[j]);
            ans2 = max(ans2, x);
        }
    }
    cout << ans << endl << ans2 << endl;
    return 0;
}


