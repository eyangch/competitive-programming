#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<int> edges[3000];
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    unordered_set<int> closed;
    for(int i = 0; i < N; i++){
        stack<int> dfs;
        int start = 0;
        for(; closed.find(start) != closed.end(); start++){}
        dfs.push(start);
        unordered_set<int> been;
        while(!dfs.empty()){
            int idx = dfs.top();
            dfs.pop();
            if(been.find(idx) != been.end() || closed.find(idx) != closed.end()){
                continue;
            }
            been.insert(idx);
            for(int j : edges[idx]){
                dfs.push(j);
            }
        }
        if(been.size() == N - i){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        int rm;
        cin >> rm;
        closed.insert(rm - 1);
    }
    return 0;
}
