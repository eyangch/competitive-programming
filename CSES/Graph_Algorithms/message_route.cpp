#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100000];
int di[100000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    fill(di, di+N, -1);
    queue<pair<int, int>> q;
    q.push({N-1, 1});
    while(!q.empty()){
        int id = q.front().first, d = q.front().second;
        q.pop();
        if(~di[id]) continue;
        di[id] = d;
        for(int i : graph[id]){
            q.push({i, d+1});
        }
    }
    if(!~di[0]){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << di[0] << endl << 1 << " ";
        int i = 0;
        while(i != N-1){
            for(int adj : graph[i]){
                if(di[adj] == di[i]-1){
                    i = adj;
                    break;
                }
            }
            cout << i+1 << " ";
        }
        cout << endl;
    }
}
