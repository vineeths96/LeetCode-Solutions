class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> charFreqTracker;
        for (const char &ch : s1)
            charFreqTracker[ch]++;

        int windowStart = 0;
        int windowEnd = 0;
        while (windowEnd < s2.size()) {
            char currentChar = s2[windowEnd];
            if (charFreqTracker.find(currentChar) != charFreqTracker.end()) {
                charFreqTracker[currentChar]--;
                
                if (charFreqTracker[currentChar] == 0)
                    charFreqTracker.erase(currentChar);

                if (charFreqTracker.size() == 0)
                    return true;
                
                windowEnd++;
            } else {
                if (windowStart == windowEnd)
                    windowEnd++;
                else
                    charFreqTracker[s2[windowStart]]++;

                windowStart++;
            }
        }

        return false;
    }
};