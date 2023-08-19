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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        std::queue<std::pair<int, TreeNode*>> bfsQueue;
        bfsQueue.push(std::make_pair(0, root));

        std::vector<std::vector<int>> levelOrderTraversal;
        while (!bfsQueue.empty()) {
            auto front = bfsQueue.front();
            bfsQueue.pop();

            int level = front.first;
            TreeNode* node = front.second;

            if (levelOrderTraversal.size() == level)
                levelOrderTraversal.push_back({});

            levelOrderTraversal[level].push_back(node->val);

            if (node->left) bfsQueue.push(std::make_pair(level + 1, node->left));
            if (node->right) bfsQueue.push(std::make_pair(level + 1, node->right));
        }

        return levelOrderTraversal;
    }
};