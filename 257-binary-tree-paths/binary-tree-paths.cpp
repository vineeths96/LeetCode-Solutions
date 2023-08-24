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
    std::vector<std::string> paths;

    void dfsHelper(TreeNode* root, std::string currentPath) {
        if (root == nullptr)
            return;
        
        currentPath += std::to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
            this->paths.push_back(currentPath);
        else {
            currentPath += "->";
            if (root->left != nullptr) dfsHelper(root->left, currentPath);
            if (root->right != nullptr) dfsHelper(root->right, currentPath);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::string currentPath;
        dfsHelper(root, currentPath);

        return paths;
    }
};