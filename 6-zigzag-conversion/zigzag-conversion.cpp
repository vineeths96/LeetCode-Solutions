class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        int numCols = numRows - 1;
        int numCharsinBlock = numRows + numCols - 1;
        int numBlocks = std::ceil(s.size() / (float) numCharsinBlock);

        std::vector<std::vector<char>> matrix(numRows, std::vector<char>(numCols * numBlocks, ' '));
        
        int rowIndex = 0;
        int colIndex = 0;
        int strIndex = 0;
        while (strIndex < s.size()) {
            for (; (strIndex < s.size()) && (rowIndex < numRows); rowIndex++, strIndex++) 
                matrix[rowIndex][colIndex] = s[strIndex];

            rowIndex--;

            for (int i = 0; (strIndex < s.size()) && (i < numCols); i++, strIndex++) 
                matrix[--rowIndex][++colIndex] = s[strIndex];
            
            rowIndex = 1;
        }

        std::string result;
        for (int i = 0; i < matrix.size(); i++)
         for (int j = 0; j < matrix[0].size(); j++)
            if (matrix[i][j] != ' ')
                result.push_back(matrix[i][j]);

        return result;
    }
};