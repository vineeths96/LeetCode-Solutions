class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : s1)
            charFreqMap[ch]++;

        for (int windowStart = 0, windowEnd = 0; windowEnd < s2.size();) {
            char currentChar = s2[windowEnd];
 
            if (charFreqMap.find(currentChar) != charFreqMap.end()) {
                charFreqMap[currentChar]--;

                if (charFreqMap[currentChar] == 0)
                    charFreqMap.erase(currentChar);

                if (charFreqMap.size() == 0)
                    return true;

                windowEnd++;
            } else if (windowStart < windowEnd) {
                charFreqMap[s2[windowStart]]++;
                windowStart++;
            } else {
                windowStart++;
                windowEnd++;
            }
        }

        return false;
    }
};