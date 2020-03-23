#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> belong[N], groups[M];
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        for(int j = 0; j < x; j++){
            int a; cin >> a;
            belong[a-1].push_back(i);
            groups[i].push_back(a-1);
        }
    }
    set<int> been;
    set<int> bgroup;
    int ans[N];
    for(int i = 0; i < N; i++){
        if(been.find(i) != been.end()){
            continue;
        }
        queue<int> bfs;
        bfs.push(i);
        set<int> curr;
        curr.insert(i);
        while(!bfs.empty()){
            int idx = bfs.front();
            bfs.pop();
            for(int j : belong[idx]){
                if(bgroup.find(j) != bgroup.end()) continue;
                for(int k : groups[j]){
                    if(been.find(k) != been.end()) continue;
                    been.insert(k);
                    bfs.push(k);
                    curr.insert(k);
                }
                bgroup.insert(j);
            }
        }
        for(int j : curr){
            ans[j] = curr.size();
        }
    }
    for(int i : ans){
        cout << i << " ";
    }cout << endl;
    return 0;
}
