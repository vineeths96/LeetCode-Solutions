class Solution {
public:
    string removeDuplicates(string s) {
        std::string charStack;

        for (const char &ch : s) {
            if (!charStack.empty() && ch == charStack.back())
                charStack.pop_back();
            else
                charStack.push_back(ch);
        }

        return charStack;
    }
};