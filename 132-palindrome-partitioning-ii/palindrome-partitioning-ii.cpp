class Solution {
    std::vector<std::vector<int>> dpVector;

    bool isPalindrome(const std::string &str, int left, int right) {
        while (left < right) {
            if (str[left++] != str[right--])
                return false;
        }

        return true;
    }

    int minCutRecursive(const std::string &str, int start, int end) {
        if (start > end)
            return 0;

        if (dpVector[start][end] != -1)
            return dpVector[start][end];

        int minCuts = end - start + 1;
        for (int ind = start; ind <= end; ind++) {
            if (isPalindrome(str, start, ind))
                minCuts = std::min(minCuts, (ind == end ? 0 : 1) + minCutRecursive(str, ind + 1, end));
        }

        return dpVector[start][end] = minCuts;
    }

public:
    int minCut(string s) {
        dpVector = std::vector<std::vector<int>>(s.size(), std::vector<int>(s.size(), -1));
        return minCutRecursive(s, 0, s.size() - 1);
    }
};