class Solution {
    struct TrieNode {
        bool isWord = false;
        std::unordered_map<char, TrieNode*> charMap;

        TrieNode() : isWord(false), charMap(std::unordered_map<char, TrieNode*>()) {};
    };
    
    void findWordsHelper(std::vector<std::vector<char>> &board, TrieNode *root, std::string &currentWord, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return;

        if (!root->charMap.contains(board[x][y]))
            return;

        char holder = board[x][y];
        board[x][y] = '#';

        root = root->charMap[holder];
        currentWord.push_back(holder);

        if (root->isWord)
            allWords.insert(currentWord);

        for (const auto &dir : dirs) {
            int xDash = x + dir[0];
            int yDash = y + dir[1];

            findWordsHelper(board, root, currentWord, xDash, yDash);
        }

        currentWord.pop_back();
        board[x][y] = holder;
    }

    TrieNode *root;
    std::unordered_set<std::string> allWords;
    std::vector<std::vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        for (const auto &word : words) {
            TrieNode *current = root;
            for (const auto &ch : word) {
                if (!current->charMap.contains(ch))
                    current->charMap[ch] = new TrieNode();

                current = current->charMap[ch];
            }

            current->isWord = true;
        }

        std::string currentWord;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                findWordsHelper(board, root, currentWord, i, j);

        return std::vector<std::string>(allWords.begin(), allWords.end());
    }
};