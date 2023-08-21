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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        std::queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        int depth = 0;
        while (!bfsQueue.empty()) {
            int numNodesInLevel = bfsQueue.size();
            depth++;

            for (int i = 0; i < numNodesInLevel; i++) {
                TreeNode *node = bfsQueue.front();
                bfsQueue.pop();

                if (node->left == nullptr && node->right == nullptr)
                    return depth;

                if (node->left != nullptr) bfsQueue.push(node->left);
                if (node->right != nullptr) bfsQueue.push(node->right);
            }
        }

        return depth;
    }
};