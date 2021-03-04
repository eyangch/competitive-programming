#include <bits/stdc++.h>
#define endl "\n"
#define moo cout
#define f first
#define s second
#define int long long

using namespace std;

int N, M, d[100000];
vector<pair<int, int>> graph[100000];

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, w; cin >> a >> b >> w;
        graph[a-1].push_back({b-1, w});
        graph[b-1].push_back({a-1, w});
    }
    fill_n(d, 100000, 1e15);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    d[0] = 0;
    while(!pq.empty()){
        int id = pq.top().s, di = pq.top().f;
        pq.pop();
        if(d[id] != di) continue;
        for(pair<int, int> i : graph[id]){
            if(d[i.f] > d[id] + i.s){
                d[i.f] = d[id] + i.s;
                pq.push({d[i.f], i.f});
            }
        }
    }
    if(d[N-1] == 1e15){
        moo << -1 << endl;
        return 0;
    }
    stack<int> ans;
    int id = N-1;
    while(true){
        ans.push(id+1);
        if(id == 0) break;
        for(pair<int, int> i : graph[id]){
            if(d[i.f] == d[id] - i.s) id = i.f;
        }
    }
    while(!ans.empty()){
        moo << ans.top() << " ";
        ans.pop();
    }
    moo << endl;
}
