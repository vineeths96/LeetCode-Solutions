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
    int pathSums = 0;

    void dfsHelper(TreeNode *root, int currentSum) {
        if (root == nullptr)
            return;

        currentSum = currentSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            pathSums += currentSum;
        else {
            if (root->left != nullptr) dfsHelper(root->left, currentSum);
            if (root->right != nullptr) dfsHelper(root->right, currentSum);
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        dfsHelper(root, 0);
        return pathSums;        
    }
};