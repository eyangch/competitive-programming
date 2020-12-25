#include <bits/stdc++.h>

using namespace std;

struct loc{int x; int doge; int d; bool r;};

int N, M;
int b[30000], p[30000];
vector<int> graph[30000];
int dist[30000];
unordered_set<int> vis;

signed main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> b[i] >> p[i];
        graph[b[i]].push_back(i);
    }
    fill(dist, dist+N, -1);
    deque<loc> q;
    q.push_back({b[0], 0, 0, true});
    q.push_back({b[0], 0, 0, false});
    vis.reserve(7000000);
    while(!q.empty()){
        if(~dist[b[1]]) break;
        int x = q.front().x, doge = q.front().doge, d = q.front().d;
        bool r = q.front().r;
        q.pop_front();
        if(!(~dist[x])){
            dist[x] = d;
            for(int i : graph[x]){
                q.push_front({x, i, d, true});
                q.push_front({x, i, d, false});
            }
        }
        int dv = p[doge];
        if(!r) dv = -dv;
        x += dv;
        d++;
        int id = x + 30000*p[doge] + 30000*30000*r;
        if(x < 0 || x >= N || vis.find(id) != vis.end()) continue;
        vis.insert(id);
        if((int)vis.size() > 6000000) vis.erase(vis.begin());
        q.push_back({x, doge, d, r});
    }
    cout << dist[b[1]] << endl;
}
