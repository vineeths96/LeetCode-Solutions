/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool lowestCommonAncestorHelper(TreeNode* root, TreeNode *p, TreeNode* q) {
        if (root == nullptr)
            return false;

        bool foundNode = (root == p || root == q);
        bool foundLeft = lowestCommonAncestorHelper(root->left, p, q);
        bool foundRight = lowestCommonAncestorHelper(root->right, p, q);

        if (foundNode && foundLeft || foundNode && foundRight || foundLeft && foundRight)
            lcaNode = root;

        return foundNode || foundLeft || foundRight;
    }

    TreeNode *lcaNode;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lowestCommonAncestorHelper(root, p, q);
        return lcaNode;
    }
};