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
    double target;
    std::deque<int> deque;

    void inorderTraversal(TreeNode *root, int k) {
        if (root == nullptr)
            return;

        inorderTraversal(root->left, k);

        deque.push_back(root->val);
        if (deque.size() > k) {
            if (std::abs(deque.front() - target) < std::abs(deque.back() - target))
                deque.pop_back();
            else
                deque.pop_front();
        }

        inorderTraversal(root->right, k); 
    }

public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        this->target = target;

        inorderTraversal(root, k);
        
        std::vector<int> kClose;
        while (!deque.empty()) {
            kClose.push_back(deque.front());
            deque.pop_front();
        }

        return kClose;
    }
};