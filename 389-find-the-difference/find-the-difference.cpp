class Solution {
public:
    char findTheDifference(string s, string t) {
        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : s)
            charFreqMap[ch]++;

        for (const char &ch : t) {
            charFreqMap[ch]--;

            if (charFreqMap[ch] == 0)
                charFreqMap.erase(ch);
        }

        return charFreqMap.begin()->first;
    }
};