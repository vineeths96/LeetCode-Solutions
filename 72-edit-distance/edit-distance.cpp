class Solution {
public:
    int minDistance(string word1, string word2) {
        std::vector<std::vector<int>> dpVector(word1.size() + 1, std::vector<int>(word2.size() + 1, std::numeric_limits<int>::max()));
        
        for (int i = 0; i < dpVector.size(); i++)
            dpVector[i][0] = i;

        for (int j = 0; j < dpVector[0].size(); j++)
            dpVector[0][j] = j;

        for (int i = 1; i < dpVector.size(); i++) {
            for (int j = 1; j < dpVector[0].size(); j++) {
                if (word1[i - 1] == word2[j - 1])
                    dpVector[i][j] = dpVector[i - 1][j - 1];
                else {
                    dpVector[i][j] = std::min(dpVector[i][j], 1 + dpVector[i - 1][j - 1]);
                    dpVector[i][j] = std::min(dpVector[i][j], 1 + dpVector[i][j - 1]);
                    dpVector[i][j] = std::min(dpVector[i][j], 1 + dpVector[i - 1][j]);
                }
            }
        }

        return dpVector[word1.size()][word2.size()];
    }
};