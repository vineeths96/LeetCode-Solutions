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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        std::queue<std::pair<int, TreeNode*>> bfsQueue;
        bfsQueue.push({0, root});

        std::vector<std::vector<int>> zigzagLevelOrderTraversal;
        while (!bfsQueue.empty()) {
            auto front = bfsQueue.front();
            bfsQueue.pop();
            
            int level = front.first;
            TreeNode *node = front.second;

            if (zigzagLevelOrderTraversal.size() == level)
                zigzagLevelOrderTraversal.push_back({});

            zigzagLevelOrderTraversal[level].push_back(node->val);

            if (node->left != nullptr) bfsQueue.push({level + 1, node->left});
            if (node->right != nullptr) bfsQueue.push({level + 1, node->right});
        }

        for (int i = 0; i < zigzagLevelOrderTraversal.size(); i++)
            if (i % 2 == 1)
                std::reverse(zigzagLevelOrderTraversal[i].begin(), zigzagLevelOrderTraversal[i].end());

        return zigzagLevelOrderTraversal;
    }
};