class Solution {
    struct TrieNode {
        bool isWord;
        std::unordered_map<char, TrieNode*> children;
    };

    TrieNode *root;

public:
    string longestCommonPrefix(vector<string>& strs) {
        root = new TrieNode();

        for (const auto &str : strs) {
            TrieNode *current = root;
            for (const char &ch : str) {
                if (!current->children.contains(ch))
                    current->children[ch] = new TrieNode();

                current = current->children[ch];
            }

            current->isWord = true;
        }

        std::string prefix;
        while (!root->isWord && root->children.size() == 1) {
            prefix.append(1, root->children.begin()->first);
            root = root->children.begin()->second;
        }

        return prefix;
    }
};