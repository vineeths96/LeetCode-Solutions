class Solution {
    std::vector<int> dpVector;

    bool isPalindrome(const std::string &str, int start, int end) {
        while (start < end) {
            if (str[start++] != str[end--])
                return false;
        }

        return true;
    }

    int minCutRecursive(const std::string &str, int currentIndex) {
        if (currentIndex >= str.size())
            return 0;

        if (dpVector[currentIndex] != -1)
            return dpVector[currentIndex];

        int minCuts = str.size() - currentIndex;
        for (int ind = currentIndex; ind < str.size(); ind++) {
            if (isPalindrome(str, currentIndex, ind))
                minCuts = std::min(minCuts, (ind == str.size() - 1 ? 0 : 1) + minCutRecursive(str, ind + 1));
        }

        return dpVector[currentIndex] = minCuts;
    }

public:
    int minCut(string s) {
        dpVector = std::vector<int>(s.size(), -1);
        return minCutRecursive(s, 0);
    }
};