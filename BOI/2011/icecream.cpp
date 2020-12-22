#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> bad[200];
int ok[200];

int dfs(int id, int d){
    if(d == 2) return 1;
    for(int i : bad[id]){
        ok[i]++;
    }
    int ret = 0;
    for(int i = id+1; i < N; i++){
        if(!ok[i]){
            ret += dfs(i, d+1);
        }
    }
    for(int i : bad[id]){
        ok[i]--;
    }
    return ret;
}

signed main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        if(b < a) swap(a, b);
        bad[a-1].push_back(b-1);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += dfs(i, 0);
    }
    cout << ans << endl;
}
