#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define int long long

using namespace std;
typedef pair<int, int> pii;

int N, M, K;
vector<pii> graph[100000];
vector<int> di[100000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a-1].push_back({b-1, c});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        int id = pq.top().se, d = pq.top().fi;
        pq.pop();
        if((int)di[id].size() >= K) continue;
        di[id].push_back(d);
        for(pii i : graph[id]){
            if((int)di[i.fi].size() >= K) continue;
            pq.push({d + i.se, i.fi});
        }
    }
    for(int i : di[N-1]){
        cout << i << " ";
    }
    cout << endl;
}
