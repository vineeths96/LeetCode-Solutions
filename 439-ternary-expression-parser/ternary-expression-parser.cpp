class Solution {
public:
    string parseTernary(string expression) {
        std::string charStack;

        bool sawQues = false;
        for (int i = expression.size() - 1; i >= 0; i--) {
            char ch = expression[i];
            if (sawQues) {
                char t = charStack.back();
                charStack.pop_back();

                char f = charStack.back();
                charStack.pop_back();

                if (ch == 'T') charStack.push_back(t);
                else charStack.push_back(f);

                sawQues = false;
            } else {
                if (std::isalpha(ch) || std::isdigit(ch))
                    charStack.push_back(ch);
                else if (ch == '?')
                    sawQues = true;
            }
        }

        return std::string(1, charStack.back());
    }
};