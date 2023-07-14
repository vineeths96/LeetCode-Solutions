class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        std::unordered_map<char, int> distinctChars;
        int subStringLength = 0;

        for (int i = 0; i < s.size(); i++) {
            distinctChars[s[i]]++;

            if (distinctChars.size() <= k)
                subStringLength++;
            else {
                distinctChars[s[i - subStringLength]]--;

                if (distinctChars[s[i - subStringLength]] == 0)
                    distinctChars.erase(s[i - subStringLength]);
            }
        }

        return subStringLength;
    }
};