class Solution {
public:
    char findTheDifference(string s, string t) {
        int charBitRep = 0;
        for (const char &ch : s)
            charBitRep = charBitRep ^ 1 << (ch - 'a');

        for (const char &ch : t)
            charBitRep = charBitRep ^ 1 << (ch - 'a');

        return 'a' + std::log2(charBitRep);
    }
};