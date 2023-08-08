class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : t)
            charFreqMap[ch]++;

        std::vector<int> minWindow{std::numeric_limits<int>::max(), 0, 0};
        int matched = 0;
        std::unordered_map<char, int> windowCharFreqMap;
        for (int windowStart = 0, windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            char windowEndChar = s[windowEnd];
            windowCharFreqMap[windowEndChar]++;
            
            if (charFreqMap.count(windowEndChar) != 0 && windowCharFreqMap[windowEndChar] == charFreqMap[windowEndChar])
                matched++;

            while (windowStart <= windowEnd && matched == charFreqMap.size()) {
                if (windowEnd - windowStart + 1 < minWindow[0]) {
                    minWindow[0] = windowEnd - windowStart + 1;
                    minWindow[1] = windowStart;
                    minWindow[2] = windowEnd;
                }

                char windowStartChar = s[windowStart];
                windowCharFreqMap[windowStartChar]--;
                windowStart++;
                if (charFreqMap.count(windowStartChar) != 0 && windowCharFreqMap[windowStartChar] < charFreqMap[windowStartChar])
                    matched--;
            }
        }

        return minWindow[0] == std::numeric_limits<int>::max() ? "" : s.substr(minWindow[1], minWindow[0]);
    }
};