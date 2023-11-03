class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        std::vector<std::vector<int>> dpVector(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));

        for (int i = 1; i < dpVector.size(); i++) {
            for (int j = 1; j < dpVector[0].size(); j++) {
                if (text1[i - 1] == text2[j - 1])
                    dpVector[i][j] = 1 + dpVector[i - 1][j - 1];
                else
                    dpVector[i][j] = std::max(dpVector[i - 1][j], dpVector[i][j - 1]);
            }
        }
        
        return dpVector[text1.size()][text2.size()];
    }
};