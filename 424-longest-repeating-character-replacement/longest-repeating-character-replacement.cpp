class Solution {
private:
    bool subStringWithSameLetter(std::string str, int windowSize, int k) {
        int maxFrequency = std::numeric_limits<int>::min();
        std::unordered_map<char, int> charFreqMap;

        for (int windowEnd = 0; windowEnd < str.size(); windowEnd++) {
            charFreqMap[str[windowEnd]]++;

            if (windowEnd >= windowSize)
                charFreqMap[str[windowEnd - windowSize]]--;

            maxFrequency = std::max(maxFrequency, charFreqMap[str[windowEnd]]);

            if (windowSize - maxFrequency <= k)
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

            if (subStringWithSameLetter(s, mid, k)) 
                left = mid + 1;
            else
                right = mid;
        }

        return left - 1;
    }
};