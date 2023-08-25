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
    int maxPathSumValue = std::numeric_limits<int>::min();

    int dfsHelper(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int leftTreeSum = std::max(dfsHelper(root->left), 0);
        int rightTreeSum = std::max(dfsHelper(root->right), 0);
        
        this->maxPathSumValue = std::max({this->maxPathSumValue, root->val + leftTreeSum + rightTreeSum}); 
        return root->val + std::max(leftTreeSum, rightTreeSum);
    }


public:
    int maxPathSum(TreeNode* root) {
        dfsHelper(root);
        return this->maxPathSumValue;
    }
};