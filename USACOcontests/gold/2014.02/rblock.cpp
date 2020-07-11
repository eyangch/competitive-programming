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

struct node{
    int dest;
    int id;
};

int N, M;
vector<node> graph[100];
int paths[10000];
int dist[100];
bool vis[100];

vi spath;

int dij(int x2, bool store){
    fill(dist, dist+N, INT_MAX);
    fill(vis, vis+N, false);
    dist[0] = 0;
    for(int i = 0; i < N-1; i++){
        int minN = INT_MAX;
        int minidx = 0;
        for(int j = 0; j < N; j++){
            if(!vis[j] && dist[j] <= minN){
                minN = dist[j];
                minidx = j;   
            }
        }
        vis[minidx] = true;
        for(node j : graph[minidx]){
            if(vis[j.dest]){
                continue;
            }
            if(dist[minidx] + paths[j.id] * (1+(j.id == x2)) < dist[j.dest]){
                dist[j.dest] = dist[minidx] + paths[j.id] * (1+(j.id == x2));
            }
        }
    }
    if(store){
        int idx = N-1;
        while(idx > 0){
            int minN = INT_MAX;
            int minidx = 0;
            int minid = 0;
            for(node i : graph[idx]){
                if(dist[i.dest] + paths[i.id] <= minN){
                    minN = dist[i.dest] + paths[i.id];
                    minidx = i.dest;
                    minid = i.id;
                }
                //cout << paths[i.id] + dist[i.dest] << endl;
            }
            //cout << "MINN: " << minN << endl;
            spath.push_back(minid);
            idx = minidx;
        }
    }
    return dist[N-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("rblock.in", "r", stdin);
    freopen("rblock.out", "w", stdout);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v, l; cin >> u >> v >> l; 
        paths[i] = l;
        node n1 = {u-1, i};
        node n2 = {v-1, i};
        graph[u-1].push_back(n2);
        graph[v-1].push_back(n1);
    }
    int tdist = dij(-1, true);
    //cout << tdist << endl;
    int ans = 0;
    for(int i : spath){
        //cout << paths[i] << " " << dij(i, false) << endl;
        ans = max(ans, dij(i, false));
    }
    cout << ans - tdist << endl;
    return 0;
}
