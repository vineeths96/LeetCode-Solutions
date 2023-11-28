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
    void serializeHelper(const TreeNode *root, std::string &encoded) {
        if (root == nullptr)
            encoded += "X,";
        else {
            encoded += std::to_string(root->val) + ",";
            serializeHelper(root->left, encoded);
            serializeHelper(root->right, encoded);
        }
    }

    TreeNode* deserializeHelper(std::stringstream &nodes) {
        std::string val;
        std::getline(nodes, val, ',');
        
        if (val == "X")
            return nullptr;

        TreeNode *root = new TreeNode(std::stoi(val));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);

        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string encoded;
        serializeHelper(root, encoded);
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream nodes(data);
        return deserializeHelper(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));