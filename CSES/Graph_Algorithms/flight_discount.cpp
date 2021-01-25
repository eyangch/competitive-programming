#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define endl "\n"

using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<pii> graph[100000], rgraph[100000];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int di[100000], di2[100000];

void dij(int s){
    fill(di, di+N, 1e17);
    pq.push({0, s});
    di[s] = 0;
    while(!pq.empty()){
        int id = pq.top().se, d = pq.top().fi;
        pq.pop();
        if(di[id] != d) continue;
        for(pii i : graph[id]){
            if(di[i.fi] > di[id] + i.se){
                di[i.fi] = di[id] + i.se;
                pq.push({di[i.fi], i.fi});
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a-1].push_back({b-1, c});
        rgraph[b-1].push_back({a-1, c});
    }
    dij(0);
    copy(di, di+N, di2);
    for(int i = 0; i < N; i++){
        graph[i] = rgraph[i];
    }
    dij(N-1);
    int ans = 1e17;
    for(int i = 0; i < N; i++){
        for(pii j : graph[i]){
            ans = min(ans, di[i] + di2[j.fi] + j.se / 2);
        }
    }
    cout << ans << endl;
}
