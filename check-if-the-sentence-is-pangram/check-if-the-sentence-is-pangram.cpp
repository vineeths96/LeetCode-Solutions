class Solution {
public:
    bool checkIfPangram(string sentence) {
        std::transform(sentence.begin(), sentence.end(), sentence.begin(), 
                        [](char ch) { return std::tolower(ch); });

        std::array<int, 26> freqVec{0};
        for (const char& ch : sentence)
            freqVec[ch - 'a']++;

        for (const int& freq : freqVec)
            if (freq == 0)
                return false;

        return true;
    }
};