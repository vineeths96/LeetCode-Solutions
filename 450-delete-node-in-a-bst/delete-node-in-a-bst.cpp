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
    int findSuccessor(TreeNode *root) {
        while (root->left != nullptr)
            root = root->left;

        return root->val;
    }

    int findPredecessor(TreeNode *root) {
        while (root->right != nullptr)
            root = root->right;

        return root->val;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (root->right != nullptr) {
                root->val = findSuccessor(root->right);
                root->right = deleteNode(root->right, root->val);
            } else if (root->left != nullptr) {
                root->val = findPredecessor(root->left);
                root->left = deleteNode(root->left, root->val);
            } else
                root = nullptr;
        }

        return root;
    }
};