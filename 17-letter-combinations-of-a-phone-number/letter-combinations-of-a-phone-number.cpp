class Solution {
    std::unordered_map<char, std::vector<char>> charMap;
    std::vector<string> allStrings;

    void letterCombinationsHelper(const std::string &digits, int currentIndex, std::string currentString) {
        if (currentIndex == digits.size()) {
            if (!currentString.empty())
                allStrings.push_back(currentString);
                
            return;
        }

        for (const char &ch : charMap[digits[currentIndex]]) {
            currentString.push_back(ch);
            letterCombinationsHelper(digits, currentIndex + 1, currentString);
            currentString.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        charMap['2'] = {'a', 'b', 'c'};
        charMap['3'] = {'d', 'e', 'f'};
        charMap['4'] = {'g', 'h', 'i'};
        charMap['5'] = {'j', 'k', 'l'};
        charMap['6'] = {'m', 'n', 'o'};
        charMap['7'] = {'p', 'q', 'r', 's'};
        charMap['8'] = {'t', 'u', 'v'};
        charMap['9'] = {'w', 'x', 'y', 'z'};

        std::string currentString;
        letterCombinationsHelper(digits, 0, currentString);

        return allStrings;
    }
};