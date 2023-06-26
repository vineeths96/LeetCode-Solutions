class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        std::unordered_map<char, int> distinctChars;
        int subStringLength = std::numeric_limits<int>::min();

        for (int windowStart = 0, windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            distinctChars[s[windowEnd]]++;

            while (windowStart <= windowEnd && distinctChars.size() > k) {
                char charToErase = s[windowStart];

                while (distinctChars[charToErase] > 0) {
                    distinctChars[s[windowStart]]--;

                    if (distinctChars[s[windowStart]] == 0)
                        distinctChars.erase(s[windowStart]);

                    windowStart++;

                    if (distinctChars.size() <= k)
                        break;
                }
            }

            subStringLength = std::max(subStringLength, windowEnd - windowStart + 1);
        }

        return subStringLength;
    }
};