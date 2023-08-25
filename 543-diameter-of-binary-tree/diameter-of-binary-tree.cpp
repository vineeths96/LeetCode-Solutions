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
    int treeDiameter = 0;

    int dfsHelper(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int leftTreeHeight = dfsHelper(root->left);
        int rightTreeHeight = dfsHelper(root->right);

        this->treeDiameter = std::max(this->treeDiameter, leftTreeHeight + rightTreeHeight);

        return 1 + std::max(leftTreeHeight, rightTreeHeight);

    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfsHelper(root);
        return this->treeDiameter;
    }
};