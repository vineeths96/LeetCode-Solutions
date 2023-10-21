class Solution {
public:
    int longestPalindromeSubseq(string s) {
        std::vector<std::vector<int>> dpVector(s.size(), std::vector<int>(s.size(), 0));

        for (int i = 0; i < dpVector.size(); i++)
            dpVector[i][i] = 1;

        for (int start = dpVector.size() - 1; start >= 0; start--) {
            for (int end = start + 1; end < dpVector[0].size(); end++) {
                int longestLength = 0;
                if (s[start] == s[end])
                    longestLength = 2 + dpVector[start + 1][end - 1];
                else
                    longestLength = std::max(dpVector[start][end - 1], dpVector[start + 1][end]);

                dpVector[start][end] = longestLength;
            }
        }

        return dpVector[0][s.size() - 1];
    }
};