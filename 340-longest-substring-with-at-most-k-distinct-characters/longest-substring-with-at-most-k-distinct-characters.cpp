class Solution {
private:
    bool findSubstringOfSize(std::string s, int windowSize, int k) {
        std::unordered_map<char, int> distinctChars;

        for (int i = 0; i < windowSize; i++)
            distinctChars[s[i]]++;

        if (distinctChars.size() <= k)
            return true;

        for (int i = windowSize; i < s.size(); i++) {
            distinctChars[s[i]]++;
            distinctChars[s[i - windowSize]]--;

            if (distinctChars[s[i - windowSize]] == 0)
                distinctChars.erase(s[i - windowSize]);

            if (distinctChars.size() <= k)
                return true;
        }

        return false;
    }


public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0;
        int right = s.size() + 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (findSubstringOfSize(s, mid, k))
                left = mid + 1;
            else
                right = mid;
        }

        return left - 1;
    }
};