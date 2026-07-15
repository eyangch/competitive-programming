class Solution {
public:
    pair<int, int> dfs(int v, int p, int k, vector<int> &values, vector<vector<int>> &G){
        int sum = values[v];
        int n_segments = 0;
        for(int c : G[v]){
            if(c == p) continue;
            pair<int, int> c_res = dfs(c, v, k, values, G);
            sum += c_res.first;
            sum %= k;
            n_segments += c_res.second;
        }
        if(sum % k == 0){
            sum = 0;
            n_segments++;
        }
        return {sum, n_segments};
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> G(n, vector<int>());
        for(int i = 0; i < n-1; i++){
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]);
        }
        pair<int, int> res = dfs(0, -1, k, values, G);
        return res.second;
    }
};