struct trie {
    trie *children[26];
    bool end = 0;
    string s;
};

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    bool vis[12][12];
    vector<string> ans;
    void dfs(int N, int M, vector<vector<char>>& board, trie *cur, int x, int y){
        if(cur->end){
            ans.push_back(cur->s);
            cur->end = 0;
        }
        vis[x][y] = 1;
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || vis[nx][ny]) continue;
            int nc = board[nx][ny] - 'a';
            if(cur->children[nc]){
                dfs(N, M, board, cur->children[nc], nx, ny);
            }
        }
        vis[x][y] = 0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int N = board.size(), M = board[0].size();
        trie *root = new trie();
        for(string word : words){
            trie *cur = root;
            for(char c : word){
                if(cur->children[c-'a'] == nullptr){
                    cur->children[c-'a'] = new trie();
                }
                cur = cur->children[c-'a'];
            }
            cur->end = 1;
            cur->s = word;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int nc = board[i][j] - 'a';
                if(root->children[nc]){
                    dfs(N, M, board, root->children[nc], i, j);
                }
            }
        }
        return ans;
    }
};