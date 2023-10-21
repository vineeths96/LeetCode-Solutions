class Solution {
    std::vector<std::vector<int>> dpVector;

    int longestPalindromeSubseqRecursive(const std::string &str, int start, int end) {
        if (start > end) 
            return 0;

        if (start == end) 
            return 1;

        if (dpVector[start][end] != -1)
            return dpVector[start][end];

        int longestLength = 0;
        if (str[start] == str[end])
            longestLength = 2 + longestPalindromeSubseqRecursive(str, start + 1, end - 1);
        else{
            int first = longestPalindromeSubseqRecursive(str, start, end - 1);
            int second = longestPalindromeSubseqRecursive(str, start + 1, end);
            longestLength = std::max(first, second);
        }

        return dpVector[start][end] = longestLength;
    }

public:
    int longestPalindromeSubseq(string s) {
        dpVector = std::vector<std::vector<int>>(s.size() + 1, std::vector<int>(s.size() + 1, -1));
        return longestPalindromeSubseqRecursive(s, 0, s.size() - 1);
    }
};