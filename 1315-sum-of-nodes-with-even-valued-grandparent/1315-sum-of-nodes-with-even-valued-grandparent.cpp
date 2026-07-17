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
private:
    void dfs(TreeNode* node, TreeNode* par, TreeNode* gpar, int& sum) {
        if(gpar && gpar->val % 2 == 0) 
          sum += node->val;
        if(node->left) 
          dfs(node->left, node, par, sum);
        if(node->right) 
          dfs(node->right, node, par, sum);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        dfs(root, nullptr, nullptr, ans);
        return ans;
    }
};