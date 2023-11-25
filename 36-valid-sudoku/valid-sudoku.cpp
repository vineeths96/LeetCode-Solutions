class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        
        std::vector<int> rows(N, 0);
        std::vector<int> cols(N, 0);
        std::vector<int> boxes(N, 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';
                int mask = 1 << (num - 1);

                if (rows[i] & mask) return false;
                else rows[i] |= mask;

                if (cols[j] & mask) return false;
                else cols[j] |= mask;

                int boxNumber = (i / 3) * 3 + j / 3;
                if (boxes[boxNumber] & mask) return false;
                else boxes[boxNumber] |= mask;
            }
        }

        return true;
    }
};