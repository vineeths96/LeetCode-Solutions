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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return {};

        std::queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        std::vector<int> rightSideView;
        while (!bfsQueue.empty()) {
            int numNodesInLevel = bfsQueue.size();
            for (int i = 0; i < numNodesInLevel; i++) {
                TreeNode *node = bfsQueue.front();
                bfsQueue.pop();

                if (i == numNodesInLevel - 1)
                    rightSideView.push_back(node->val);

                if (node->left != nullptr) bfsQueue.push(node->left);
                if (node->right != nullptr) bfsQueue.push(node->right);
            }
        }

        return rightSideView;
    }
};