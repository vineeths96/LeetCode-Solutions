class Solution {
    int substrStart;
    int substrEnd;
    std::vector<std::vector<int>> dpVector;

    bool longestPalindromeRecursive(const std::string &str, int start, int end) {
        if (start > end)
            return true;

        if (dpVector[start][end] != -1)
            return dpVector[start][end] == 1;

        bool longestRemaining = false;
        if (str[start] == str[end]) {
            longestRemaining = longestPalindromeRecursive(str, start + 1, end - 1);
            if (longestRemaining && substrEnd - substrStart + 1 < end - start + 1) {
                substrStart = start;
                substrEnd = end;
            }
        }
        
        if (!longestRemaining) {
            longestPalindromeRecursive(str, start + 1, end);
            longestPalindromeRecursive(str, start, end - 1);
        }

        return dpVector[start][end] = longestRemaining ? 1 : 0;
    }

public:
    string longestPalindrome(string s) {
        substrStart = s.size() - 1;
        substrEnd = 0;
        dpVector = std::vector<std::vector<int>>(s.size(), std::vector<int>(s.size(), -1)); 
        longestPalindromeRecursive(s, 0, s.size() - 1);

        return s.substr(substrStart, substrEnd - substrStart + 1);
    }
};