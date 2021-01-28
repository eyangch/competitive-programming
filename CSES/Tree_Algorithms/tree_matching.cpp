#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N;
vector<int> graph[200000];
bool p[200000];
int ans;

void dfs(int id, int par){
    for(int i : graph[id]){
        if(i == par) continue;
        dfs(i, id);
    }
    if(!p[id] && par > -1 && !p[par]){
        p[id] = p[par] = true;
        ans++;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    dfs(0, -1);
    cout << ans << endl;
}
