class Solution {
    std::vector<std::string> permutations;

    void recursionHelper(std::string &str, int currentIndex) {
        while (std::isdigit(str[currentIndex])) currentIndex++;

        if (currentIndex == str.size()) {
            permutations.push_back(str);
            return;
        }

        int delta = std::islower(str[currentIndex]) ? 'A' - 'a' : 'a' - 'A';
        str[currentIndex] += delta;
        recursionHelper(str, currentIndex + 1);
        str[currentIndex] -= delta;
        recursionHelper(str, currentIndex + 1);
    }

public:
    vector<string> letterCasePermutation(string s) {
        recursionHelper(s, 0);
        return permutations;
    }
};