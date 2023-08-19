class Solution {
public:
    string removeDuplicates(string s, int k) {
        std::string charStack;

        for (const char &ch : s) {
            charStack.push_back(ch);

            if (charStack.size() < k) continue;
            std::string lastSubString = charStack.substr(charStack.size() - k, k);
            std::string duplicateString(k, ch);

            if (lastSubString == duplicateString)
                charStack.erase(charStack.size() - k, k); 
        }

        return charStack;
    }
};