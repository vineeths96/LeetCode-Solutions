class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : t)
            charFreqMap[ch]++;

        std::vector<int> minWindow{std::numeric_limits<int>::max(), 0, 0};
        int windowStart = 0;
        int windowEnd = 0;
        int matched = 0;
        std::unordered_map<char, int> windowCharFreqMap;
        while (windowEnd < s.size()) {
            windowCharFreqMap[s[windowEnd]]++;
            
            if (charFreqMap.count(s[windowEnd]) != 0 && windowCharFreqMap[s[windowEnd]] == charFreqMap[s[windowEnd]])
                matched++;

            if (matched == charFreqMap.size()) {
                while (windowStart <= windowEnd) {
                    if (matched == charFreqMap.size()) {
                        if (windowEnd - windowStart + 1 < minWindow[0]) {
                            minWindow[0] = windowEnd - windowStart + 1;
                            minWindow[1] = windowStart;
                            minWindow[2] = windowEnd;
                        }
                    } else
                        break;

                    char windowStartChar = s[windowStart];
                    windowCharFreqMap[windowStartChar]--;
                    windowStart++;
                    if (charFreqMap.count(windowStartChar) != 0 && windowCharFreqMap[windowStartChar] < charFreqMap[windowStartChar])
                        matched--;
                }
            }

            windowEnd++;
        }

        return minWindow[0] == std::numeric_limits<int>::max() ? "" : s.substr(minWindow[1], minWindow[0]);
    }
};