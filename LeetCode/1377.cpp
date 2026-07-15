class Solution {
public:
    double prob[105];
    int depth[105];
    bool is_leaf[105];
    vector<int> G[105];
    void dfs(int v, int p, int d, double pr){
        int n_children = G[v].size();
        if(v != 0) n_children--;
        if(n_children == 0){
            is_leaf[v] = 1;
        }
        depth[v] = d;
        prob[v] = pr;
        for(int c : G[v]){
            if(c == p) continue;
            dfs(c, v, d+1, pr / n_children);
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        for(vector<int> &e : edges){
            G[e[0]-1].push_back(e[1]-1);
            G[e[1]-1].push_back(e[0]-1);
        }
        dfs(0, -1, 0, 1);
        if(depth[target-1] > t){
            return 0;
        }
        if(depth[target-1] == t){
            return prob[target-1];
        }
        if(is_leaf[target-1]){
            return prob[target-1];
        }
        return 0;
    }
};