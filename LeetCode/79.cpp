#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout

using namespace std;

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    bool vis[6][6];
    bool dfs(int N, int M, vector<vector<char>>& board, string &word, int c, int x, int y){
        if(c == word.size()-1) return 1;
        bool ok = 0;
        vis[x][y] = 1;
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || vis[nx][ny] || board[nx][ny] != word[c+1]) continue;
            ok |= dfs(N, M, board, word, c+1, nx, ny);
        }
        vis[x][y] = 0;
        return ok;
    }
    bool exist(vector<vector<char>>& board, string word) {
        const int N = board.size(), M = board[0].size();
        bool ok = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(board[i][j] != word[0]) continue;
                ok |= dfs(N, M, board, word, 0, i, j);
            }
        }
        return ok;
    }
};