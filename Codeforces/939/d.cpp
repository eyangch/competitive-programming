#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    string s1, s2;
    cin >> N >> s1 >> s2;
    unordered_set<int> let[26];
    for(int i = 0; i < N; i++){
        int c1 = (int)(s1[i] - 97), c2 = (int)(s2[i] - 97);
        let[c1].insert(c2);
        let[c2].insert(c1);
    }
    vector<pair<int, int>> edges;
    unordered_set<int> been;
    for(int i = 0; i < 26; i++){
        if(been.find(i) != been.end()){
            continue;
        }
        stack<int> dfs;
        dfs.push(i);
        been.insert(i);
        while(!dfs.empty()){
            int idx = dfs.top();
            dfs.pop();
            if(let[idx].size() == 0){
                continue;
            }
            for(int j : let[idx]){
                if(been.find(j) != been.end()){
                    continue;
                }
                edges.push_back(make_pair(min(idx, j), max(idx, j)));
                been.insert(j);
                dfs.push(j);
            }
        }
    }
    sort(edges.begin(), edges.end());
    vector<pair<int, int>>::iterator it1 = unique(edges.begin(), edges.end());
    edges.resize(std::distance(edges.begin(), it1));
    cout << edges.size() << endl;
    for(int i = 0; i < edges.size(); i++){
        cout << (char)(edges[i].first + 97) << " " << (char)(edges[i].second + 97) << endl;
    }
    return 0;
}
