class Solution {
    struct TrieNode {
        std::string isWord;
        std::unordered_map<char, TrieNode*> children;

        TrieNode() : isWord(""), children(std::unordered_map<char, TrieNode*>()) {};
    };
    
    void findWordsHelper(std::vector<std::vector<char>> &board, TrieNode *root, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return;

        if (!root->children.contains(board[x][y]))
            return;

        char holder = board[x][y];
        board[x][y] = '#';

        TrieNode *child = root->children[holder];
        if (!child->isWord.empty()) {
            allWords.push_back(child->isWord);
            child->isWord = "";
        }

        for (const auto &dir : dirs) {
            int xDash = x + dir[0];
            int yDash = y + dir[1];

            findWordsHelper(board, child, xDash, yDash);
        }

        if (child->children.empty())
            root->children.erase(holder);

        board[x][y] = holder;
    }

    TrieNode *root;
    std::vector<std::string> allWords;
    std::vector<std::vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        for (const auto &word : words) {
            TrieNode *current = root;
            for (const auto &ch : word) {
                if (!current->children.contains(ch))
                    current->children[ch] = new TrieNode();

                current = current->children[ch];
            }

            current->isWord = word;
        }

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                findWordsHelper(board, root, i, j);

        return allWords;
    }
};