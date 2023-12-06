class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = matrix.size() - 1;
        int colEnd = matrix[0].size() - 1;

        std::vector<int> spiral;
        while (rowStart <= rowEnd || colStart <= colEnd) {
            for (int j = colStart; rowStart <= rowEnd && j < colEnd; j++)
                spiral.push_back(matrix[rowStart][j]);

            for (int i = rowStart; colStart <= colEnd && i <= rowEnd; i++)
                spiral.push_back(matrix[i][colEnd]);

            for (int j = colEnd - 1; rowStart < rowEnd && j > colStart; j--)
                spiral.push_back(matrix[rowEnd][j]);

            for (int i = rowEnd; colStart < colEnd && i > rowStart; i--)
                spiral.push_back(matrix[i][colStart]);

            rowStart++;
            rowEnd--;
            colStart++;
            colEnd--;
        }

        return spiral;
    }
};