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
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::less<std::pair<double, int>>> maxHeap;

    void inorderTraversal(TreeNode *root, int k) {
        if (root == nullptr)
            return;

        inorderTraversal(root->left, k);

        maxHeap.push({std::abs(root->val - target), root->val});
        if (maxHeap.size() > k)
            maxHeap.pop();

        inorderTraversal(root->right, k); 
    }

public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        this->target = target;

        inorderTraversal(root, k);
        
        std::vector<int> kClose;
        while (!maxHeap.empty()) {
            kClose.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return kClose;
    }
};