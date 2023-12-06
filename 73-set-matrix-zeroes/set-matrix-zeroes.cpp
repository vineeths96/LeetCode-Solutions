class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        std::vector<std::pair<int, int>> zeroes;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] == 0)
                    zeroes.push_back({i, j});

        for (const auto &zero : zeroes) {
            auto [x, y] = zero;
            
            for (int j = 0; j < cols; j++)
                matrix[x][j] = 0;
                
            for (int i = 0; i < rows; i++)
                matrix[i][y] = 0;                
        }
    }
};