class Solution {
    std::vector<std::string> permutations;

    void recursionHelper(std::string str, int currentIndex) {
        while (str[currentIndex] >= '0' && str[currentIndex] <= '9') currentIndex++;

        if (currentIndex == str.size()) {
            permutations.push_back(str);
            return;
        }

        int delta = str[currentIndex] >= 'a' && str[currentIndex] <= 'z' ? 'A' - 'a' : 'a' - 'A';
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