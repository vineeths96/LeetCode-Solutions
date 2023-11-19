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
    int preIndex = 0;
    std::unordered_map<int, int> inOrderMap;

    TreeNode* buildTreeRecurisve(const std::vector<int> &preorder, const std::vector<int> &inorder, int inStart, int inEnd) {
        if (preIndex == preorder.size() || inStart > inEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preIndex++]);

        root->left = buildTreeRecurisve(preorder, inorder, inStart, inOrderMap[root->val] - 1);
        root->right = buildTreeRecurisve(preorder, inorder, inOrderMap[root->val] + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            inOrderMap[inorder[i]] = i;

        return buildTreeRecurisve(preorder, inorder, 0, inorder.size() - 1);  
    }
};