class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::array<int, 26> charFreqArray{0};

        for (const char &ch : magazine)
            charFreqArray[ch - 'a']++;

        for (const char &ch : ransomNote) {
            charFreqArray[ch - 'a']--;
            if (charFreqArray[ch - 'a'] < 0) 
                return false;
        }

        return true;
    }
};