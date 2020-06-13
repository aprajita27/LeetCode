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
    int isBalancedHelper(TreeNode* root, bool& isBal) {
        if(!root)
            return 0;
        int lHeight = isBalancedHelper(root->left, isBal);
        int rHeight = isBalancedHelper(root -> right, isBal);
        if (abs(lHeight - rHeight) > 1)
            isBal = false;
        return max(lHeight, rHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool isBal = true;
        isBalancedHelper(root, isBal);
        return isBal;
    }
};
