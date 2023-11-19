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
    bool isValidBSTRecursive(TreeNode *root, long int loBound, long int upBound) {
        if (root == nullptr)
            return true;

        if (root->val <= loBound || root->val >= upBound)
            return false;

        return isValidBSTRecursive(root->left, loBound, root->val) && isValidBSTRecursive(root->right,root->val, upBound);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTRecursive(root, std::numeric_limits<long int>::min(), std::numeric_limits<long int>::max());
    }
};