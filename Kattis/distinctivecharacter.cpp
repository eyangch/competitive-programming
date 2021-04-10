#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, K;
bool vis[1<<21];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> K;
    queue<int> q;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        q.push(stoi(s, 0, 2));
    }
    int ans = 0;
    while(!q.empty()){
        int id = q.front();
        q.pop();
        if(vis[id]) continue;
        vis[id] = true;
        ans = id;
        for(int i = 0; i < K; i++){
            q.push(id ^ (1<<i));
        }
    }
    moo << bitset<20>(ans).to_string().substr(20-K) << endl;
}
