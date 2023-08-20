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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr)
            return {};

        std::queue<std::pair<int, TreeNode*>> bfsQueue;
        bfsQueue.push({0, root});

        std::deque<std::vector<int>> reverseLevelOrderTraversal;
        while (!bfsQueue.empty()) {
            auto front = bfsQueue.front();
            bfsQueue.pop();
            
            int level = front.first;
            TreeNode *node = front.second;

            if (reverseLevelOrderTraversal.size() == level)
                reverseLevelOrderTraversal.push_front({});

            reverseLevelOrderTraversal.front().push_back(node->val);

            if (node->left != nullptr) bfsQueue.push({level + 1, node->left});
            if (node->right != nullptr) bfsQueue.push({level + 1, node->right});
        }

        return std::vector<std::vector<int>>(reverseLevelOrderTraversal.begin(), reverseLevelOrderTraversal.end());
    }
};