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
    std::map<std::pair<int, int>, std::vector<TreeNode*>> dpMap;

    std::vector<TreeNode*> generateTreesHelper(int start, int end) {
        if (start > end)
            return {nullptr};

        if (dpMap.find({start, end}) != dpMap.end())
            return dpMap[{start, end}];
        
        std::vector<TreeNode*> roots;
        for (int i = start; i <= end; i++) {
            std::vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
            std::vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);

            for (const auto &left : leftTrees) {
                for (const auto &right : rightTrees) {
                    TreeNode *root = new TreeNode(i, left, right);
                    roots.push_back(root);
                }
            }
        }

        return dpMap[{start, end}] = roots;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesHelper(1, n);
    }
};