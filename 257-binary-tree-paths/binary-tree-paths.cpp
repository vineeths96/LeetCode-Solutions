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

    void dfsHelper(TreeNode* root, std::vector<int> &currentPath) {
        if (root == nullptr)
            return;
        
        currentPath.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr)
            this->paths.push_back(currentPath);
        else {
            if (root->left != nullptr) dfsHelper(root->left, currentPath);
            if (root->right != nullptr) dfsHelper(root->right, currentPath);
        }
        currentPath.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<int> currentPath;
        dfsHelper(root, currentPath);

        std::vector<std::string> stringPaths;
        for (const auto &path : paths) {
            std::string stringPath;
            for (const int node : path)
                stringPath += std::to_string(node) + "->";

            stringPath.erase(stringPath.size() - 2);
            stringPaths.push_back(stringPath);
        }

        return stringPaths;
    }
};