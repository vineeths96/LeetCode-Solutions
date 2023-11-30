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
    TreeNode *predecessor = nullptr;
    TreeNode *first = nullptr, *second = nullptr;

    void inOrderTraversal(TreeNode *root) {
        if (root == nullptr)
            return;

        inOrderTraversal(root->left);

        if (predecessor != nullptr && predecessor->val > root->val) {
            if (first == nullptr) {
                first = predecessor;
                second = root;
            } else {
                second = root;
                return;
            }
        }

        predecessor = root;
        inOrderTraversal(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inOrderTraversal(root);
        std::swap(first->val, second->val);
    }
};