#include <bits/stdc++.h>

using namespace std;

struct s{
    int i, p, d;
};

int N, M;
vector<int> graph[2500];
int di[2500];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    unsigned int ans = -1;
    for(int i = 0; i < N; i++){
        fill(di, di+N, -1);
        queue<s> q;
        q.push({i, i, 0});
        while(!q.empty()){
            s cur = q.front();
            q.pop();
            int x = cur.i, p = cur.p, d = cur.d;
            if(~di[x]){
                ans = min(ans, (unsigned int)d + di[x]);
                continue;
            }
            di[x] = d;
            for(int i : graph[x]){
                if(i == p) continue;
                q.push({i, x, d+1});
            }
        }
    }
    cout << (int)ans << endl;
}
