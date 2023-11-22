class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
    
        std::vector<int> dpVector(s.size() + 1, 0);
        dpVector[0] = 1;
        dpVector[1] = 1;
        for (int i = 2; i < dpVector.size(); i++) {
            std::string potentialNumber;
            potentialNumber.push_back(s[i - 2]);
            potentialNumber.push_back(s[i - 1]);
            int potentialNumberInt = std::stoi(potentialNumber);
            if (potentialNumberInt >= 10 && potentialNumberInt <= 26)
                dpVector[i] += dpVector[i - 2];

            int currentNumber = s[i - 1] - '0';
            if (currentNumber > 0 && currentNumber <= 9)
                dpVector[i] += dpVector[i - 1];
        }

        return dpVector[s.size()];
    }
};