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
    void inorder(TreeNode *root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        if (--this->k == 0) kthSmallestNum = root->val;
        inorder(root->right);
    }

    int k = 0;
    int kthSmallestNum = 0;

public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder(root);

        return kthSmallestNum;
    }
};