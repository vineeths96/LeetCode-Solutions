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

        std::queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        bool leftToRight = true;
        std::vector<std::vector<int>> zigzagLevelOrderTraversal;
        while (!bfsQueue.empty()) {
            int numNodesInLevel = bfsQueue.size();
            std::vector<int> levelNodes(numNodesInLevel, 0);

            for (int i = 0; i < numNodesInLevel; i++) {
                TreeNode *node = bfsQueue.front();
                bfsQueue.pop();
                
                if (leftToRight)
                    levelNodes[i] = node->val;
                else
                    levelNodes[numNodesInLevel-1-i] = node->val;

                if (node->left != nullptr) bfsQueue.push(node->left);
                if (node->right != nullptr) bfsQueue.push(node->right);
            }

            zigzagLevelOrderTraversal.push_back(levelNodes);
            leftToRight = !leftToRight;
        }

        return zigzagLevelOrderTraversal;
    }
};