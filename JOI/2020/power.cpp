#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N;
vector<int> graph[200000];
char s[200001];
int ans = 0;

int dfs(int id, int par){
    int p = s[id] - '0', ret = p, c = 0, mxc = 0;
    for(int i : graph[id]){
        if(i == par) continue;
        int cur = dfs(i, id);
        if(cur == 0) continue;
        c++;
        mxc = max(mxc, cur);
        ret += cur;
    }
    if(p && c > 0){
        ans = (c-1 ? max({ans, ret-2, mxc+1}) : max(ans, ret));
        ret -= 2;
    }
    ans = max(ans, ret);
    return max(p, ret);
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
    cin >> s;
    dfs(0, 0);
    cout << ans << endl;
}
