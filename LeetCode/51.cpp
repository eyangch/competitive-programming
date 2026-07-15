class Solution {
public:
    int N;
    int f[9][9], b[9][9];
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    vector<vector<string>> ans;
    void add_board(){
        vector<string> cur;
        for(int i = 0; i < N; i++){
            string s = "";
            for(int j = 0; j < N; j++){
                if(b[i][j]) s += 'Q';
                else s += '.';
            }
            cur.push_back(s);
        }
        ans.push_back(cur);
    }
    void set_queen(int x, int y, int v){
        b[x][y] += v;
        f[x][y] += v;
        for(int k = 0; k < 8; k++){
            int x_ = x + dx[k], y_ = y + dy[k];
            while(x_ >= 0 && x_ < N && y_ >= 0 && y_ < N){
                f[x_][y_] += v;
                x_ += dx[k], y_ += dy[k];
            }
        }
    }
    void dfs(int row){
        if(row == N){
            add_board();
            return;
        }
        for(int i = 0; i < N; i++){
            if(!f[row][i]){
                set_queen(row, i, 1);
                dfs(row+1);
                set_queen(row, i, -1);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        dfs(0);
        return ans;
    }
};