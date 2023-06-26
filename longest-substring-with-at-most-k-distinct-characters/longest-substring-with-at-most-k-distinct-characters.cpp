class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        std::unordered_map<char, int> distinctChars;
        int subStringLength = std::numeric_limits<int>::min();

        for (int windowStart = 0, windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            distinctChars[s[windowEnd]]++;

            while (windowStart <= windowEnd && distinctChars.size() > k) {
                distinctChars[s[windowStart]]--;

                if (distinctChars[s[windowStart]] == 0)
                    distinctChars.erase(s[windowStart]);

                windowStart++;
            }

            subStringLength = std::max(subStringLength, windowEnd - windowStart + 1);
        }

        return subStringLength;
    }
};