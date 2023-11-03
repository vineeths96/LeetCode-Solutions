class Solution {
    std::vector<std::vector<int>> dpVector;

    int longestCommonSubsequenceRecursive(const std::string &text1, const std::string &text2, int index1, int index2) {
        if (index1 == text1.size() || index2 == text2.size())
            return 0;

        if (dpVector[index1][index2] != -1)
            return dpVector[index1][index2];

        int result = 0;
        if (text1[index1] == text2[index2]) 
            result = 1 + longestCommonSubsequenceRecursive(text1, text2, index1 + 1, index2 + 1);
        else
            result = std::max(longestCommonSubsequenceRecursive(text1, text2, index1 + 1, index2), longestCommonSubsequenceRecursive(text1, text2, index1, index2 + 1));

        return dpVector[index1][index2] = result;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        dpVector = std::vector<std::vector<int>>(text1.size() + 1, std::vector<int>(text2.size() + 1, -1));
        return longestCommonSubsequenceRecursive(text1, text2, 0, 0);
    }
};