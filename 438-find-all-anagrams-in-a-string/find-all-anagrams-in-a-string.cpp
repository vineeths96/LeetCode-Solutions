class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : p)
            charFreqMap[ch]++;

        std::vector<int> anagramStartIndices;
        int windowStart = 0;
        int windowEnd = 0;
        while (windowEnd < s.size()) {
            char currentChar = s[windowEnd];
            if (charFreqMap.find(currentChar) != charFreqMap.end()) {
                charFreqMap[currentChar]--;

                if (charFreqMap[currentChar] == 0)
                    charFreqMap.erase(currentChar);

                if (charFreqMap.empty())
                    anagramStartIndices.push_back(windowStart);

                windowEnd++;
            } else {
                if (windowStart == windowEnd)
                    windowEnd++;
                else
                    charFreqMap[s[windowStart]]++;

                windowStart++;
            }
        }

        return anagramStartIndices;
    }
};