class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        std::vector<std::vector<bool>> dpVector(s.size(), std::vector<bool>(s.size(), false));

        for (int i = 0; i < dpVector.size(); i++)
            for (int j = 0; j <= i; j++)
                dpVector[i][j] = true;

        count += dpVector.size();
        for (int start = dpVector.size() - 1; start >= 0; start--) {
            for (int end = start + 1; end < dpVector[0].size(); end++) {
                if (s[start] == s[end] && dpVector[start + 1][end - 1]) {
                    dpVector[start][end] = true;
                    count++;
                }
            }
        }

        return count;
    }
};