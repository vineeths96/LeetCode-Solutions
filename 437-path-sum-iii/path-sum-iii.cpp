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
public:
    std::unordered_map<long long, int> prefixSum;

    int dfsHelper(TreeNode *root, int targetSum, long long currentSum) {
        int numPaths = 0;
        if (root == nullptr)
            return numPaths;
        
        currentSum += root->val;
        if (prefixSum.find(currentSum - targetSum) != prefixSum.end())
            numPaths += prefixSum[currentSum - targetSum];
            
        prefixSum[currentSum]++;
        if (root->left != nullptr) numPaths += dfsHelper(root->left, targetSum, currentSum);
        if (root->right != nullptr) numPaths += dfsHelper(root->right, targetSum, currentSum);
        prefixSum[currentSum]--;

        return numPaths;        
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefixSum.insert({0, 1});
        return dfsHelper(root, targetSum, 0);
    }
};