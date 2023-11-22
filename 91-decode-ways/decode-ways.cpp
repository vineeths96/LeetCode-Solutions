class Solution {
    std::vector<std::vector<int>> dpVector;

    int numDecodingsRecursive(const std::string &str, int currentIndex, int prevDigit) {
        if (currentIndex == str.size()) 
            return 1;

        if (dpVector[currentIndex][prevDigit + 1] != -1)
            return dpVector[currentIndex][prevDigit + 1];

        int numWays = 0;
        int currentDigit = str[currentIndex] - '0';
        int potentialNumber = prevDigit * 10 + currentDigit;
        if (prevDigit != -1 && potentialNumber <= 26)
            numWays += numDecodingsRecursive(str, currentIndex + 1, potentialNumber);

        if (currentDigit > 0 && currentDigit <= 9)
            numWays += numDecodingsRecursive(str, currentIndex + 1, currentDigit);

        return dpVector[currentIndex][prevDigit + 1] = numWays;
    }

public:
    int numDecodings(string s) {
        dpVector = std::vector<std::vector<int>>(s.size(), std::vector<int>(28, -1));
        return numDecodingsRecursive(s, 0, -1);
    }
};