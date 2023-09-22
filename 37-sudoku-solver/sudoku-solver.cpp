class Solution {
    bool canPlace(const std::vector<std::vector<char>> &board, char k, int i, int j) {
        if (board[i][j] != '.')
            return false;

        for (int val = 0; val < 9; val++) 
            if (board[i][val] == k || board[val][j] == k)
                return false;

        for (int x = (i / 3) * 3; x < (i / 3 + 1) * 3; x++) {
            for (int y = (j / 3) * 3; y < (j / 3 + 1) * 3; y++) {
                if (board[x][y] == k) 
                    return false;
            }
        }        

        return true;
    }

    bool solveSudokuRecursive(std::vector<std::vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        char num = k + '0';
                        if (canPlace(board, num, i, j)) {
                            board[i][j] = num;
                            if(solveSudokuRecursive(board)) return true;
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuRecursive(board);
    }
};