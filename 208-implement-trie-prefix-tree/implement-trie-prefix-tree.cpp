class Trie {
    struct TrieNode {
        bool isWord;
        std::unordered_map<char, TrieNode*> children;
    };

    TrieNode *root;

public:
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *current = root;
        for (const char &ch : word) {
            if (current->children.find(ch) == current->children.end())
                current->children[ch] = new TrieNode();
            
            current = current->children[ch];
        }

        current->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *current = root;
        for (const char &ch : word) {
            if (current->children.find(ch) == current->children.end())
                return false;
            
            current = current->children[ch];
        }

        return current->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *current = root;
        for (const char &ch : prefix) {
            if (current->children.find(ch) == current->children.end())
                return false;
            
            current = current->children[ch];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */