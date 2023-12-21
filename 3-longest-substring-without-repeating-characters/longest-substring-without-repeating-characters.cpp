class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        std::unordered_map<char, int> charFreqMap;

        for (int windowStart = 0, windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            charFreqMap[s[windowEnd]]++;

            while (windowStart <= windowEnd && charFreqMap[s[windowEnd]] > 1) {
                charFreqMap[s[windowStart]]--;
                windowStart++;
            }

            maxLength = std::max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};