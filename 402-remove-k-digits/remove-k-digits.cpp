class Solution {
public:
    string removeKdigits(string num, int k) {
        std::string charStack;

        for (const char &ch : num) {
            while (!charStack.empty() && charStack.back() > ch && k > 0) {
                charStack.pop_back();
                k--;
            }

            if (charStack.empty() && ch == '0') 
                continue;

            charStack.push_back(ch);
        }

        while (!charStack.empty() && k > 0) {
            charStack.pop_back();
            k--;
        }

        return charStack.size() ? charStack : "0";
    }
};