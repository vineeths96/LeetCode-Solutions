class Solution {
public:
    int characterReplacement(string s, int k) {
        std::array<int, 26> freqVector{0};
        int maxFrequency =  0;
        int subStringLength = std::numeric_limits<int>::min();

        for (int windowStart = 0, windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            freqVector[s[windowEnd] - 'A']++;
            maxFrequency = std::max(maxFrequency, freqVector[s[windowEnd] - 'A']);

            if (windowEnd - windowStart + 1 - maxFrequency > k) {
                freqVector[s[windowStart] - 'A']--;
                windowStart++;
            }

            subStringLength = std::max(subStringLength, windowEnd - windowStart + 1);
        }

        return subStringLength;
    }
};