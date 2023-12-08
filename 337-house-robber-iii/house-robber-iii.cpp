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
    std::map<std::pair<TreeNode*, bool>, int> dp;

public:
    int rob(TreeNode* root, bool skipLevel=false) {
        if (root == nullptr)
            return 0;

        if (dp.contains({root, skipLevel}))
            return dp[{root, skipLevel}];

        int robRoot = 0, skipRoot = 0;
        if (!skipLevel)
            robRoot = root->val + rob(root->left, true) + rob(root->right, true);
        
        skipRoot = rob(root->left, false) + rob(root->right, false);

        return dp[{root, skipLevel}] = std::max(robRoot, skipRoot);
    }
};