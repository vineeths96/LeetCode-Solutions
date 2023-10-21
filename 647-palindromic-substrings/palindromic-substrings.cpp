class Solution {
    int count;
    std::vector<std::vector<int>> dpVector;

    bool countSubstringsRecursive(const std::string &str, int start, int end) {
        if (start > end)
            return true;
        
        if (dpVector[start][end] != -1)
            return dpVector[start][end] == 1;

        bool isPalindrome = false;
        if (str[start] == str[end]) {
            isPalindrome = countSubstringsRecursive(str, start + 1, end - 1);
            if (isPalindrome) count++;
        }

        countSubstringsRecursive(str, start + 1, end);
        countSubstringsRecursive(str, start, end - 1);

        return dpVector[start][end] = isPalindrome ? 1 : 0;
    }

public:
    int countSubstrings(string s) {
        count = 0;
        dpVector = std::vector<std::vector<int>>(s.size(), std::vector<int>(s.size(), -1));
        countSubstringsRecursive(s, 0, s.size() - 1);
        return count;
    }
};