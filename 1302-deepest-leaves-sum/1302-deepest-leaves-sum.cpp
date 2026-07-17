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
    void solve(TreeNode* r, int h, int &l, int &s) {
        if(!r) return;
        if(l == h)
          s+= r->val;
        if(l < h) l = h, s = r->val;
          solve(r->left, h+1, l, s);
          solve(r->right, h+1, l, s);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int l = 0, s =0;
        solve(root, 0, l, s);
        return s; 
    }
};