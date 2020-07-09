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

void assign_time(int N, vi (&graph)[200000], int (&in_time)[200000], int (&out_time)[200000], int idx, int &time){
    if(in_time[idx] != -1){
        return;
    }
    in_time[idx] = time;
    time++;
    for(int i : graph[idx]){
        assign_time(N, graph, in_time, out_time, i, time);
    }
    out_time[idx] = time;
    time++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    vi graph[200000];
    for(int i = 0; i < N-1; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);   
    } 
    int depth[N];
    fill(depth, depth+N, -1);
    queue<pii> bfs;
    bfs.push(pii(0, 0));
    while(!bfs.empty()){
        int idx = bfs.front().first, d = bfs.front().second;
        bfs.pop();
        if(depth[idx] != -1) continue;
        depth[idx] = d;
        for(int i : graph[idx]){
            bfs.push(pii(i, d+1));
        }
    }
    int in_time[200000], out_time[200000];
    fill(in_time, in_time+N, -1);
    int time = 0;
    assign_time(N, graph, in_time, out_time, 0, time);
    for(int i = 0; i < M; i++){
        int k; cin >> k;
        int v[k];
        for(int j = 0; j < k; j++){
            cin >> v[j];
            v[j]--;
            for(int p : graph[v[j]]){
                if(depth[p] < depth[v[j]]){
                    v[j] = p;
                    break;
                }
            }
        }
        sort(v, v+k, [&depth](int a, int b){
            return depth[a] < depth[b];
        });
        int lo = in_time[v[0]];
        int hi = out_time[v[0]];
        bool good = true;
        for(int i = 1; i < k; i++){
            if(in_time[v[i]] < lo || in_time[v[i]] > hi || out_time[v[i]] < lo || out_time[v[i]] > hi){
                good = false;
                break;
            }else{
                lo = in_time[v[i]];
                hi = out_time[v[i]];
            }
        }
        if(good){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}


