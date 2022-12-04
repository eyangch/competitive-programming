class Solution {
public:
    vector<int> G[100000];
    pair<long long, pair<long long, long long>> dfs(int v, int p, int seats){ // {cars, seats avail}
        long long cs = 0, sa = 0;
        long long res = 0;
        for(int c : G[v]){
            if(c == p) continue;
            pair<long long, pair<long long, long long>> cr = dfs(c, v, seats);
            sa += cr.second.second;
            res += cr.first + cr.second.first;
        }
        sa++;
        cs = (sa + seats - 1) / seats;
        return {res, {cs, sa}};
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        for(auto v : roads){
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        return dfs(0, 0, seats).first;
    }
};