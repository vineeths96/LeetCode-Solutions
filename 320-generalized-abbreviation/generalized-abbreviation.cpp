class Solution {
    std::vector<std::string> abbreviation;

    void recursionHelper(const std::string &word, int currentIndex, int count, std::string currentString) {
        if (currentIndex == word.size()) {
            if (count != 0) currentString += std::to_string(count);
            abbreviation.push_back(currentString);
            return;
        }

        recursionHelper(word, currentIndex + 1, count + 1, currentString);

        if (count != 0) currentString += std::to_string(count);
        currentString.push_back(word[currentIndex]);
        recursionHelper(word, currentIndex + 1, 0, currentString);
    }

public:
    vector<string> generateAbbreviations(string word) {
        std::string currentString;
        recursionHelper(word, 0, 0, currentString);
        return abbreviation;
    }
};