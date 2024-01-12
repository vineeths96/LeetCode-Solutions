class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        std::stack<char> charStack;

        for (const char &ch : s)
            if (std::isdigit(ch) || std::isalpha(ch))
                charStack.push(std::toupper(ch));

        int charsInGroup = 0;
        std::string formattedString;
        while (!charStack.empty()) {
            char ch = charStack.top();
            charStack.pop();

            formattedString.push_back(ch);
            if (++charsInGroup % k == 0)
                formattedString.push_back('-');
        }

        if (!formattedString.empty() && formattedString.back() == '-') 
            formattedString.pop_back();
        
        std::reverse(formattedString.begin(), formattedString.end());
        return formattedString;
    }
};