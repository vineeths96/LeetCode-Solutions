/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void preorder(TreeNode* root, std::stringstream &encoded) {
        if (root == nullptr)
            return;

        encoded << std::to_string(root->val) << ',';
        preorder(root->left, encoded);
        preorder(root->right, encoded);
    }

    TreeNode* buildTree(const std::vector<int> &preorder, int lowerBound, int upperBound) {
        if (index == preorder.size() || preorder[index] < lowerBound || preorder[index] > upperBound)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[index++]);
        root->left = buildTree(preorder, lowerBound, root->val);
        root->right = buildTree(preorder, root->val, upperBound);       

        return root;
    }

    int index = 0;

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::stringstream encoded;
        preorder(root, encoded);
        return encoded.str();        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream encoded(data);

        std::vector<int> preorder;
        while (true) {
            std::string val;
            std::getline(encoded, val, ',');

            if (val.empty()) break;
            preorder.push_back(std::stoi(val));
        }

        TreeNode *root = buildTree(preorder, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;