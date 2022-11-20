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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        for(int q : queries){
            vector<int> v;
            int mx = 1e9, mn = -1;
            TreeNode *cur = root;
            while(cur != nullptr){
                if(cur->val > q){
                    mx = min(mx, cur->val);
                    cur = cur->left;
                }else if(cur->val < q){
                    mn = max(mn, cur->val);
                    cur = cur->right;
                }else{
                    mn = mx = cur->val;
                    break;
                }
            }
            v.push_back(mn);
            v.push_back((mx == 1e9 ? -1 : mx));
            res.push_back(v);
        }
        return res;
    }
};