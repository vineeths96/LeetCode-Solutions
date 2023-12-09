class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLength = 0;
        for (int uniqueChars = 1; uniqueChars <= 26; uniqueChars++) {
            int matched = 0;
            std::unordered_map<char, int> charFreqMap;
 
            for (int windowStart = 0, windowEnd = 0; windowEnd < s.size(); windowEnd++) {
                charFreqMap[s[windowEnd]]++;

                if (charFreqMap[s[windowEnd]] == k) 
                    matched++;

                while (charFreqMap.size() > uniqueChars) {
                    charFreqMap[s[windowStart]]--;

                    if (charFreqMap[s[windowStart]] == k - 1)
                        matched--;
                    
                    if (charFreqMap[s[windowStart]] == 0)
                        charFreqMap.erase(s[windowStart]);

                    windowStart++;
                }

                if (charFreqMap.size() == matched)
                    maxLength = std::max(maxLength, windowEnd - windowStart + 1);
            }
        }

        return maxLength;
    }
};