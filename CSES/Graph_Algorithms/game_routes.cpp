#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

ll MOD = 1e9+7;
int N, M, deg[100000];
vector<int> graph[100000];
ll dp[100000];

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        deg[b-1]++;
    }
    dp[0] = 1;
    queue<int> q;
    for(int i = 0; i < N; i++){
        if(!deg[i]) q.push(i);
    }
    while(!q.empty()){
        int id = q.front();
        q.pop();
        for(int i : graph[id]){
            dp[i] = (dp[i] + dp[id]) % MOD;
            if(!--deg[i]){
                q.push(i);
            }
        }
    }
    cout << dp[N-1] << endl;
}
