class WordDictionary {
    struct TrieNode {
        bool isWord;
        std::unordered_map<char, TrieNode*> children;
    };

    bool searchFromNode(TrieNode *node, const std::string &word) {
        if (node == nullptr)
            return false;

        TrieNode *current = node;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (ch != '.') {
                if (!current->children.contains(ch))
                    return false;

                current = current->children[ch];
            } else {
                bool result = false;
                std::string currentString = word.substr(i, std::string::npos);
                for (const auto &kvPair : current->children) {
                    currentString[0] = kvPair.first;
                    result = result || searchFromNode(current, currentString);
                    currentString[0] = '.';
                }

                return result;
            }
        }

        return current->isWord;        
    }

    TrieNode *root;

public:
    WordDictionary() {
        this->root = new TrieNode();    
    }
    
    void addWord(string word) {
        TrieNode *current = root;
        for (const char &ch : word) {
            if (!current->children.contains(ch))
                current->children[ch] = new TrieNode();

            current = current->children[ch];
        }

        current->isWord = true;
    }
    
    bool search(string word) {
        return searchFromNode(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */