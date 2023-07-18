class Solution {
private:
    bool substringOfSizeExists(std::string str, int size, int k) {
        int max_frequency = std::numeric_limits<int>::min();
        std::unordered_map<char, int> charFreqMap;

        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < str.size(); windowEnd++) {
            charFreqMap[str[windowEnd]]++;

            if (windowEnd - windowStart + 1 > size) {
                charFreqMap[str[windowStart]]--;
                windowStart++;
            }

            max_frequency = std::max(max_frequency, charFreqMap[str[windowEnd]]);

            if (size - max_frequency <= k)
                return true;
        }

        return false;
    }

public:
    int characterReplacement(string s, int k) {
        int left = 1;
        int right = s.size() + 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (substringOfSizeExists(s, mid, k))
                left = mid + 1;
            else
                right = mid;
        }

        return left - 1;
    }
};