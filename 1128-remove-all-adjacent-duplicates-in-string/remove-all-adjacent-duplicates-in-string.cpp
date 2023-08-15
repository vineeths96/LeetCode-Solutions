class Solution {
public:
    string removeDuplicates(string s) {
        std::stack<char> charStack;

        for (const char &ch : s) {
            if (!charStack.empty() && ch == charStack.top())
                charStack.pop();
            else
                charStack.push(ch);
        }

        std::string unique(charStack.size(), '0');
        int index = charStack.size() - 1;
        while (!charStack.empty()) {
            unique[index] = charStack.top();
            charStack.pop();
            index--;
        }

        return unique;
    }
};