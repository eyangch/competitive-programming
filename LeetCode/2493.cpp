class Solution {
public:
    vector<int> G[500];
    int D[500], gr[500];
    int bfs(int v, int n){
        fill(D, D+n, -1);
        D[v] = 1;
        queue<pair<int, int>> q;
        q.push({v, -1});
        int mx = 0;
        while(!q.empty()){
            int cv = q.front().first;
            int p = q.front().second;
            q.pop();
            for(int c : G[cv]){
                if(c == p) continue;
                if(D[c] == -1){
                    D[c] = D[cv]+1;
                    q.push({c, cv});
                }else{
                    if(D[c] != D[cv]+1 && D[c] != D[cv]-1){
                        //cout << D[c] << ' ' << c << ' ' << cv << ' ' << D[cv]+1 << endl;
                        return -1;
                    }
                }
            }
            mx = max(mx, D[cv]);
        }
        return mx;
    }
    bool vis[500];
    void dfs(int v, vector<int> &curv){
        if(vis[v]) return;
        vis[v] = 1;
        curv.push_back(v);
        for(int c : G[v]){
            dfs(c, curv);
        }
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        for(vector<int> &v : edges){
            G[v[0]-1].push_back(v[1]-1);
            G[v[1]-1].push_back(v[0]-1);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            vector<int> cpt;
            dfs(i, cpt);
            int cans = -1;
            for(int j : cpt){
                cans = max(cans, bfs(j, n));
            }
            if(cans == -1){
                return -1;
            }
            ans += cans;
        }
        return ans;
    }
};