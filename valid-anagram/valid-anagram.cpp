class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 26> freqVec{0};

        for (const char& ch : s)
            freqVec[ch - 'a']++;

        for (const char& ch : t)
            freqVec[ch - 'a']--;

        for (const int freq : freqVec) {
            if (freq != 0)
                return false;
        }

        return true;
    }
};