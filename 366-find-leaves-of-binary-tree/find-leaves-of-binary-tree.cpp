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
    int dfsFindLeaves(TreeNode *root) {
        if (root == nullptr)    
            return 0;

        int level = std::max(dfsFindLeaves(root->left), dfsFindLeaves(root->right));

        if (leavesList.size() == level)
            leavesList.push_back({});

        leavesList[level].push_back(root->val);
        
        return level + 1;
    }

    std::vector<vector<int>> leavesList;

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfsFindLeaves(root);

        return leavesList;
    }
};