class Solution {
    bool existRecursive(std::vector<std::vector<char>> &board, std::string word, int x, int y, int currentIndex) {
        if (currentIndex == word.size())
            return true;

        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[currentIndex]) 
            return false;
        
        char ch = board[x][y];
        board[x][y] = '|';

        bool result = false;
        int dirx[] = {0, 1, 0, -1};
        int diry[] = {-1, 0, 1, 0};

        for (int k = 0; k < 4; k++) {
            int xDash = x + dirx[k];
            int yDash = y + diry[k];
            result = result || existRecursive(board, word, xDash, yDash, currentIndex + 1);
        }

        board[x][y] = ch;

        return result;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0])
                    result = result || existRecursive(board, word, i, j, 0);
            }
        }

        return result;
    }
};