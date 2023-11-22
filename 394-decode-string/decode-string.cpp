class Solution {
public:
    string decodeString(string s) {
        std::string charStack;

        for (char &ch : s) {
            if (ch != ']')
                charStack.push_back(ch);
            else {
                std::string currentString;
                while (!charStack.empty() && std::isalpha(charStack.back())) {
                    currentString.push_back(charStack.back());
                    charStack.pop_back();
                }
                std::reverse(currentString.begin(), currentString.end());

                charStack.pop_back();

                std::string numString;
                while (!charStack.empty() && std::isdigit(charStack.back())) {
                    numString.push_back(charStack.back());
                    charStack.pop_back();
                }

                std::reverse(numString.begin(), numString.end());
                int count = std::stoi(numString);
                for (int i = 0; i < count; i++)
                    charStack += currentString;
            }
        }

        return charStack;
    }
};