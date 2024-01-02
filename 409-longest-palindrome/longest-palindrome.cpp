class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> charFreqMap;

        for (const char &ch : s) 
            charFreqMap[ch]++;

        int singleTime = 0;
        int doubleTime = 0;

        for (const auto &kvPair : charFreqMap) {
            int frequency = kvPair.second;
            doubleTime += frequency / 2;
            singleTime = singleTime == 0 ? frequency % 2 : singleTime; 
        }

        return doubleTime * 2 + singleTime;
    }
};