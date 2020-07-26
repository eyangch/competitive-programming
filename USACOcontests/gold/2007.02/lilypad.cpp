#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

struct dat{
    bool type;
    ll steps;
    ll poss;
};

ll M, N;

bool vis[900];
bool vis2[900][900];

ll dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
ll dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

vector<pii> genLocs(pii loc){
    vector<pii> ans;
    for(ll i = 0; i < 8; i++){
        ll nx = loc.first+dx[i], ny = loc.second+dy[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N){
            continue;
        }
        ans.push_back(pii(nx, ny));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    ll lake[M][N];
    ll id[M][N];
    pii start, end;
    for(ll i = 0; i < M; i++){
        for(ll j = 0; j < N; j++){
            cin >> lake[i][j];
            if(lake[i][j] == 3){
                start = pii(i, j);
                lake[i][j] = 1;
            }
            if(lake[i][j] == 4){
                end = pii(i, j);
                lake[i][j] = 1;
            }
        }
    }
    fill(id[0], id[M-1]+N, -1);
    vector<dat> data;
    ll cntid = 0;
    for(ll i = 0; i < M; i++){
        for(ll j = 0; j < N; j++){
            if(id[i][j] != -1 || lake[i][j] == 2){
                continue;
            }
            dat t = {0, INT_MAX, 0};
            if(lake[i][j] == 0){
                id[i][j] = cntid;
                t.type = 1;
                data.push_back(t);
                cntid++;
                continue;
            }
            stack<pii> dfs;
            dfs.push(pii(i, j));
            while(!dfs.empty()){
                pii loc = dfs.top();
                dfs.pop();
                if(id[loc.first][loc.second] == cntid){
                    continue;
                }
                id[loc.first][loc.second] = cntid;
                vector<pii> nlocs = genLocs(loc);
                for(pii nloc : nlocs){
                    if(lake[nloc.first][nloc.second] == 1){
                        dfs.push(nloc);
                    }
                }
            }
            data.push_back(t);
            cntid++;
        }
    }
    set<ll> adj[cntid];
    for(ll i = 0; i < M; i++){
        for(ll j = 0; j < N; j++){
            if(lake[i][j] == 2){
                continue;
            }
            vector<pii> locs = genLocs(pii(i, j));
            for(pii loc : locs){
                if(id[loc.first][loc.second] == -1) continue;
                adj[id[i][j]].insert(id[loc.first][loc.second]);
            }
        }
    }
    priority_queue<pair<pii, ll>, vector<pair<pii, ll>>, greater<pair<pii, ll>>> dij;
    dij.push(make_pair(pii(0, 0), id[start.first][start.second]));
    data[id[start.first][start.second]].steps = 0;
    data[id[start.first][start.second]].poss = 1;
    ll counter = 1;
    while(!dij.empty()){
        ll d = dij.top().first.first, tid = dij.top().second;
        dij.pop();
        if(vis[tid]) continue;
        vis[tid] = true;
        for(ll nid : adj[tid]){
            if(nid == tid) continue;
            if(data[nid].type){
                if(vis2[nid][tid]) continue;
                vis2[nid][tid] = true;
                if(data[nid].steps == INT_MAX){
                    data[nid].poss = data[tid].poss;
                    data[nid].steps = data[tid].steps + 1;
                    dij.push(make_pair(pii(d+1, counter), nid));
                }else if(data[nid].steps == data[tid].steps+1){
                    data[nid].poss += data[tid].poss;
                }
            }else{
                for(ll nnid : adj[nid]){
                    if(vis2[nnid][tid]) continue;
                    vis2[nnid][tid] = true;
                    if(nnid == tid) continue;
                    if(data[nnid].type){
                        if(data[nnid].steps == INT_MAX ){
                            data[nnid].poss = data[tid].poss;
                            data[nnid].steps = data[tid].steps + 1;
                            dij.push(make_pair(pii(d+1, counter), nnid));
                        }else if(data[nnid].steps == data[tid].steps+1){
                            data[nnid].poss += data[tid].poss;
                        }
                    }
                    counter++;
                }
            }
            counter++;
        }
    }
    for(int i : adj[id[end.first][end.second]]){
        if( data[id[end.first][end.second]].steps < data[i].steps || i == id[end.first][end.second]) continue;
        if(data[id[end.first][end.second]].steps > data[i].steps) data[id[end.first][end.second]].poss = 0;
        data[id[end.first][end.second]].steps = data[i].steps;
        data[id[end.first][end.second]].poss += data[i].poss;
    }
    if(data[id[end.first][end.second]].steps != INT_MAX){
        cout << data[id[end.first][end.second]].steps << endl;
        cout << data[id[end.first][end.second]].poss << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}


