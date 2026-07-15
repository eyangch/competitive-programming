/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dp[10000][2];
    int n_cnt = 0;
    int dfs(TreeNode *v){
        int n_rob = 0;
        int y_rob = 0;
        int c = n_cnt++;
        if(v->left){
            int idx = dfs(v->left);
            n_rob += max(dp[idx][0], dp[idx][1]);
            y_rob += dp[idx][0];
        }
        if(v->right){
            int idx = dfs(v->right);
            n_rob += max(dp[idx][0], dp[idx][1]);
            y_rob += dp[idx][0];
        }
        dp[c][0] = n_rob;
        dp[c][1] = y_rob + v->val;
        return c;
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(dp[0][0], dp[0][1]);
    }
};