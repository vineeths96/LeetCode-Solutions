class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dpVector(m + 1, std::vector<int>(n + 1, 0));
        
        dpVector[1][1] = 1;
        for (int i = 1; i < dpVector.size(); i++)
            for (int j = 1; j < dpVector[0].size(); j++)
                dpVector[i][j] += dpVector[i - 1][j] + dpVector[i][j - 1];

        return dpVector[m][n];
    }
};