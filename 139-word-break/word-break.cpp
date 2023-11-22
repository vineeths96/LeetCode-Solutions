class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> dpVector(s.size() + 1, false);

        dpVector[0] = true;
        for (int i = 1; i < dpVector.size(); i++) {
            for (const auto &word : wordDict) {
                if (i < word.size())
                    continue;

                dpVector[i] = dpVector[i] || ((s.substr(i - word.size(), word.size()) == word) && dpVector[i - word.size()]);
            }
        }

        return dpVector[s.size()];
    }
};