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
    void dfsHelper(TreeNode* root, int currentSum, std::vector<int> currentPath, std::vector<std::vector<int>> &paths) {
        if (root == nullptr)
            return;
        
        currentSum -= root->val;
        currentPath.push_back(root->val);
        if (currentSum == 0 && root->left == nullptr && root->right == nullptr) {
            paths.push_back(currentPath);
            return;
        }

        if (root->left != nullptr) dfsHelper(root->left, currentSum, currentPath, paths);
        if (root->right != nullptr) dfsHelper(root->right, currentSum, currentPath, paths);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> paths;
        dfsHelper(root, targetSum, {}, paths);
        return paths;
    }
};