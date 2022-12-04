class Solution {
public:
    vector<pair<int, int>> G[100000];
    int mp = 1e9;
    bool vis[100000];
    void dfs(int v){
        if(vis[v]) return;
        vis[v] = 1;
        for(pair<int, int> e : G[v]){
            mp = min(mp, e.second);
            dfs(e.first);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        for(vector<int> &v : roads){
            G[v[0]-1].push_back({v[1]-1, v[2]});
            G[v[1]-1].push_back({v[0]-1, v[2]});
        }
        dfs(0);
        return mp;
    }
};