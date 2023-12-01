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
class BSTIterator {
    std::stack<TreeNode*> iterator;

    void populate(TreeNode *root) {
        while (root != nullptr) {
            iterator.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        populate(root);
    }
    
    int next() {
        TreeNode *top = iterator.top();
        iterator.pop();
        populate(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return iterator.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */