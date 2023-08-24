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
    std::vector<std::vector<int>> paths;

    void dfsHelper(TreeNode* root, int currentSum, std::vector<int> &currentPath) {
        if (root == nullptr)
            return;
        
        currentSum -= root->val;
        currentPath.push_back(root->val);
        if (currentSum == 0 && root->left == nullptr && root->right == nullptr) {
            this->paths.push_back(currentPath);
            currentPath.pop_back();
            return;
        }

        if (root->left != nullptr)dfsHelper(root->left, currentSum, currentPath);
        if (root->right != nullptr) dfsHelper(root->right, currentSum, currentPath);
        currentPath.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<int> currentPath;
        dfsHelper(root, targetSum, currentPath);
        return this->paths;
    }
};