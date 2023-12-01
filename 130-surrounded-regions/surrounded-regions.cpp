class Solution {
    int rows;
    int cols; 

    void dfsFind(std::vector<std::vector<char>> &board, int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols)
            return;

        if (board[x][y] != 'O')
            return;
        
        board[x][y] = '#';
        dfsFind(board, x - 1, y);
        dfsFind(board, x, y - 1);
        dfsFind(board, x + 1, y);
        dfsFind(board, x, y + 1);
    }

public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        std::vector<std::pair<int, int>> borderCells;

        for (int i = 0; i < rows; i++) {
            borderCells.push_back({i, 0});
            borderCells.push_back({i, cols - 1});
        }

        for (int j = 0; j < cols; j++) {
            borderCells.push_back({0, j});
            borderCells.push_back({rows - 1, j});
        }

        for (const auto &pair : borderCells)
            dfsFind(board, pair.first, pair.second);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};