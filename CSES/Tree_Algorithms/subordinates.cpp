#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200000];
int ans[200000];

int dfs(int id, int par){
    int ret = 1;
    for(int i : graph[id]){
        if(i != par){
            ret += dfs(i, id);
        }
    }
    ans[id] = ret;
    return ret;
}

int32_t main(){
    cin >> N;
    for(int i = 1; i < N; i++){
        int x; cin >> x;
        graph[x-1].push_back(i);
    }
    dfs(0, 0);
    for(int i = 0; i < N; i++){
        cout << ans[i]-1 << (i == N-1 ? "\n" : " ");
    }
}
