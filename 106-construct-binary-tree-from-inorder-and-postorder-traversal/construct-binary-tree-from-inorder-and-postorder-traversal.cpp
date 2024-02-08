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
    int postOrderIndex;
    std::unordered_map<int, int> inOrderMap;

    TreeNode* buildTreeRecursive(const std::vector<int> &inorder, const std::vector<int> &postorder, int start, int end) {
        if (postOrderIndex < 0 || start > end)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postOrderIndex--]);
        root->right = buildTreeRecursive(inorder, postorder, inOrderMap[root->val] + 1, end);
        root->left = buildTreeRecursive(inorder, postorder, start, inOrderMap[root->val] - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inOrderMap[inorder[i]] = i;

        postOrderIndex = postorder.size() - 1;
        return buildTreeRecursive(inorder, postorder, 0, inorder.size() - 1);
    }
};