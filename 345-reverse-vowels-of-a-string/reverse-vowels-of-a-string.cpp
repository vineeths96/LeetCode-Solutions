class Solution {
public:
    string reverseVowels(string s) {
        int start = 0;
        int end = s.size() - 1;

        std::unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        while (start < end) {
            while (start < end && vowels.count(std::tolower(s[start])) == 0)
                start++;
            
            while (start < end && vowels.count(std::tolower(s[end])) == 0)
                end--;

            std::swap(s[start], s[end]);
            start++;
            end--;
        }

        return s;
    }
};