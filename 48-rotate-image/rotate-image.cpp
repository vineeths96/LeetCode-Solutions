class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < i; j++)
                std::swap(matrix[i][j], matrix[j][i]);

        for (auto &row : matrix)
            std::reverse(row.begin(), row.end());
    }
};