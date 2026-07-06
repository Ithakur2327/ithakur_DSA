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

    int tryRob(TreeNode* root, int &l, int &r) {
        if (!root)
            return 0;

        int ll = 0, lr = 0;
        int rl = 0, rr = 0;

        // Get maximum money from left subtree
        l = tryRob(root->left, ll, lr);

        // Get maximum money from right subtree
        r = tryRob(root->right, rl, rr);

        // Rob current node
        int robCurrent = root->val + ll + lr + rl + rr;

        // Don't rob current node
        int skipCurrent = l + r;

        return max(robCurrent, skipCurrent);
    }

    int rob(TreeNode* root) {

        int l = 0;
        int r = 0;

        return tryRob(root, l, r);
    }
};