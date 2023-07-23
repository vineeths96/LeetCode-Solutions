class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : s1)
            charFreqMap[ch]++;

        int windowStart = 0;
        int windowEnd = 0;

        while (windowEnd < s2.size()) {
            char currentChar = s2[windowEnd];
 
            if (charFreqMap.find(currentChar) == charFreqMap.end()) {
                if (windowStart < windowEnd) 
                    charFreqMap[s2[windowStart]]++;
                else
                    windowEnd++;
                
                windowStart++;
            } else {
                charFreqMap[currentChar]--;

                if (charFreqMap[currentChar] == 0)
                    charFreqMap.erase(currentChar);

                if (charFreqMap.size() == 0)
                    return true;

                windowEnd++;
            }
        }

        return false;
    }
};