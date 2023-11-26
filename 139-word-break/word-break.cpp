class Solution {
    struct TrieNode {
        bool isWord;
        std::unordered_map<char, TrieNode*> children;
        TrieNode() : isWord(false), children(std::unordered_map<char, TrieNode*>()) {} 
    };

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode *root = new TrieNode();
        for (const auto &word : wordDict) {
            TrieNode *current = root;
            for (const char &ch : word) {
                if (current->children.find(ch) == current->children.end())
                    current->children[ch] = new TrieNode();
                
                current = current->children[ch];
            }

            current->isWord = true;
        } 

        std::vector<bool> dpVector(s.size() + 1, false);

        dpVector[0] = true;
        for (int i = 1; i < dpVector.size(); i++) {
            TrieNode *current = root;
            for (int j = i; j < dpVector.size(); j++) {
                if (current->children.find(s[j - 1]) == current->children.end())
                    break;
                
                current = current->children[s[j - 1]];
                dpVector[j] = dpVector[j] || (dpVector[i - 1] && current->isWord);
            }
        }

        return dpVector[s.size()];
    }
};