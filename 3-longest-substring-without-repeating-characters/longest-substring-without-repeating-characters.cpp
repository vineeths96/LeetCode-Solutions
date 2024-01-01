class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        std::unordered_map<int, int> charIndexMap;

        for (int windowStart = 0, windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            if (charIndexMap.contains(s[windowEnd]))
                windowStart = std::max(windowStart, charIndexMap[s[windowEnd]] + 1);

            maxLength = std::max(maxLength, windowEnd - windowStart + 1);
            charIndexMap[s[windowEnd]] = windowEnd;
        }

        return maxLength;
    }
};