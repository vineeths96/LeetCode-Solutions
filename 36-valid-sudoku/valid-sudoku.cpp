class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::set<std::pair<int, char>> rowSet;
        std::set<std::pair<int, char>> colSet;
        std::set<std::pair<int, char>> subBoxSet;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.')
                    continue;

                bool insertSuccess = true;
                insertSuccess = insertSuccess && rowSet.insert({i, board[i][j]}).second;
                insertSuccess = insertSuccess && colSet.insert({j, board[i][j]}).second;

                int rowStartInd = (i / 3) * 3;
                int colStartInd = (j / 3) * 3;
                insertSuccess = insertSuccess && subBoxSet.insert({rowStartInd * 10 + colStartInd, board[i][j]}).second;

                if (!insertSuccess)
                    return false;
            }
        }

        return true;
    }
};