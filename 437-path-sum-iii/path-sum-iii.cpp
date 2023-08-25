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
    int dfsHelper(TreeNode *root, int targetSum, std::vector<long long> pathSums) {
        int numPaths = 0;
        if (root == nullptr)
            return numPaths;
        
        for (long long &num : pathSums)
            num += root->val;

        pathSums.push_back(root->val);

        for (long long num : pathSums)
            if (num == targetSum) 
                numPaths++;

        if (root->left != nullptr)
            numPaths += dfsHelper(root->left, targetSum, pathSums);
        if (root->right != nullptr)
            numPaths += dfsHelper(root->right, targetSum, pathSums);

        return numPaths;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        std::vector<long long> pathSums;
        return dfsHelper(root, targetSum, pathSums);
    }
};