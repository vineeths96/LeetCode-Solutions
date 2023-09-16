class Solution {
public:
    string reorganizeString(string s) {
        char maxFrequencyLetter;
        int maxFrequency = std::numeric_limits<int>::min();
        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : s) {
            charFreqMap[ch]++;

            if (charFreqMap[ch] > maxFrequency) {
                maxFrequency = charFreqMap[ch];
                maxFrequencyLetter = ch;
            }
        }

        if (maxFrequency > (s.size() + 1) / 2) 
            return "";

        std::string reorgedString(s);
        int index = 0;
        while (charFreqMap[maxFrequencyLetter]) {
            reorgedString[index] = maxFrequencyLetter;
            index += 2;
            charFreqMap[maxFrequencyLetter]--;
        }

        for (auto &kvPair : charFreqMap) {
            while (kvPair.second) {
                if (index >= s.size()) index = 1;
                reorgedString[index] = kvPair.first;
                index += 2;
                kvPair.second--;
            }
        }

        return reorgedString;
    }
};