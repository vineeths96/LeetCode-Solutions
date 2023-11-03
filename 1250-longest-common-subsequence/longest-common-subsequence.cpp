class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        std::vector<std::vector<int>> dpVector(2, std::vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1])
                    dpVector[i % 2][j] = 1 + dpVector[(i - 1) % 2][j - 1];
                else
                    dpVector[i % 2][j] = std::max(dpVector[(i - 1) % 2][j], dpVector[i % 2][j - 1]);
            }
        }
        
        return dpVector[text1.size() % 2][text2.size()];
    }
};