class Solution {
public:
    int minCut(string s) {
        std::vector<std::vector<bool>> dpVectorPalindrome(s.size(), std::vector<bool>(s.size(), false));

        for (int start = 0; start < dpVectorPalindrome.size(); start++)
            for (int end = 0; end <= start; end++)
                dpVectorPalindrome[start][end] = true;

        for (int start = dpVectorPalindrome.size() - 1; start >= 0; start--) {
            for (int end = start + 1; end < dpVectorPalindrome[0].size(); end++) {
                if (s[start] == s[end] && dpVectorPalindrome[start + 1][end - 1])
                    dpVectorPalindrome[start][end] = true;
            }
        }

        std::vector<int> dpVector(s.size(), std::numeric_limits<int>::max());
        dpVector.back() = 0;
        for (int start = dpVector.size() - 2; start >= 0; start--) {
            for (int end = dpVector.size() - 1; end >= start; end--) {
                if (dpVectorPalindrome[start][end])
                    dpVector[start] = end == dpVector.size() - 1 ? 0 : std::min(dpVector[start], 1 + dpVector[end + 1]);
            }
        }

        return dpVector[0];
    }
};