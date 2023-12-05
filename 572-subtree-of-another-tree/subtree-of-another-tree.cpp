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
    bool checkTree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr && subRoot == nullptr) 
            return true;
        
        if (root == nullptr || subRoot == nullptr) 
            return false;

        if (root->val != subRoot->val) 
            return false;

        return checkTree(root->left, subRoot->left) && checkTree(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;

        bool result = false;
        if (root->val == subRoot->val)
            result = result || checkTree(root, subRoot);

        result = result || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        return result;
    }
};