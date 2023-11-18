class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        std::vector<std::vector<int>> dpVector(s1.size() + 1, std::vector<int>(s2.size() + 1, false));

        dpVector[0][0] = true;
        for (int i = 1; i < dpVector.size(); i++)
            dpVector[i][0] = dpVector[i - 1][0] && s1[i - 1] == s3[i - 1];

        for (int j = 1; j < dpVector[0].size(); j++)
            dpVector[0][j] = dpVector[0][j - 1] && s2[j - 1] == s3[j - 1];

        for (int i = 1; i < dpVector.size(); i++) {
            for (int j = 1; j < dpVector[0].size(); j++) {
                dpVector[i][j] |= dpVector[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                dpVector[i][j] |= dpVector[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            }
        }

        return dpVector[s1.size()][s2.size()];
    }
};