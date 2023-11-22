class Solution {
    std::vector<int> dpVector;

    bool wordBreakRecursive(const std::string &s, int currentIndex, const std::vector<std::string> &words) {
        if (currentIndex == s.size())
            return true;

        if (dpVector[currentIndex] != -1)
            return dpVector[currentIndex] == 1;

        bool result = false;
        for (const auto &word : words) {
            if (s.size() - currentIndex + 1 < word.size())
                continue;

            if (s.substr(currentIndex, word.size()) == word)
                result = result | wordBreakRecursive(s, currentIndex + word.size(), words);
        }

        return dpVector[currentIndex] = result ? 1 : 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dpVector = std::vector<int>(s.size(), -1);
        return wordBreakRecursive(s, 0, wordDict);
    }
};