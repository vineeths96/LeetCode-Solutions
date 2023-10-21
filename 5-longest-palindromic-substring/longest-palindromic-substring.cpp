class Solution {
public:
    string longestPalindrome(string s) {
        int substrStart = 0;
        int substrEnd = 0;
        std::vector<std::vector<bool>> dpVector(s.size(), std::vector<bool>(s.size(), false)); 

        for (int i = 0; i < dpVector.size(); i++)
            for (int j = 0; j <= i; j++)
                dpVector[i][j] = true;

        for (int start = dpVector.size() - 1; start >= 0; start--) {
            for (int end = start + 1; end < dpVector[0].size(); end++) {
                if (s[start] == s[end] && dpVector[start + 1][end - 1]) {
                    dpVector[start][end] = true;

                    if (substrEnd - substrStart < end - start) {
                        substrStart = start;
                        substrEnd = end;
                    }
                }
            }
        }

        return s.substr(substrStart, substrEnd - substrStart + 1);
    }
};