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
    void check(TreeNode* root, int &cnt, int maxi){
        if(!root) return;
        if(root->val >=maxi) cnt++;
        maxi=max(root->val,maxi);
        check(root->left,cnt,maxi);
        check(root->right,cnt,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt=0;
        int maxi=root->val;
        check(root,cnt,maxi);
        return cnt;
    }
};