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
    std::vector<TreeNode*> inOrder;

    void inOrderTraversal(TreeNode *root) {
        if (root == nullptr)
            return;

        inOrderTraversal(root->left);
        inOrder.push_back(root);
        inOrderTraversal(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        if (root == nullptr)
            return;

        inOrderTraversal(root);

        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        for (int i = 0; i < inOrder.size() - 1; i++) {
            if (inOrder[i]->val < inOrder[i + 1]->val) 
                continue;

            if (first == nullptr) {
                first = inOrder[i];
                second = inOrder[i + 1];
            } else {
                second = inOrder[i + 1];
                break;
            }
        }

        std::swap(first->val, second->val);
    }
};