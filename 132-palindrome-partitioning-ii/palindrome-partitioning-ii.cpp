class Solution {
    std::vector<int> dpVector;
    std::vector<std::vector<int>> dpVectorPalindrome;

    bool isPalindrome(const std::string &str, int start, int end) {
        if (dpVectorPalindrome[start][end] != -1)
            return dpVectorPalindrome[start][end] == 1;

        bool result = true;
        while (start < end) {
            if (str[start] != str[end]) {
                result = false;
                break;
            } else {
                if (dpVectorPalindrome[start + 1][end - 1] != -1)
                    result = dpVectorPalindrome[start + 1][end - 1];
                    break;
            }
        }

        return dpVectorPalindrome[start][end] = result ? 1 : 0;
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
        dpVectorPalindrome = std::vector<std::vector<int>>(s.size(), std::vector<int>(s.size(), -1));
        return minCutRecursive(s, 0);
    }
};