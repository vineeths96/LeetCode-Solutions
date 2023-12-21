class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> closingPair;
        closingPair[')'] = '(';
        closingPair[']'] = '[';   
        closingPair['}'] = '{';   

        std::stack<char> charStack;
        for (const char &ch : s) {
            if (closingPair.contains(ch)) {
                if (charStack.empty() || closingPair[ch] != charStack.top())
                    return false;
                else
                    charStack.pop();
            } else
                charStack.push(ch);
        }

        return charStack.size() == 0;
    }
};