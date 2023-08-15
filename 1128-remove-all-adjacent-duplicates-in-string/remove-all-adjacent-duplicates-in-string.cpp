class Solution {
public:
    string removeDuplicates(string s) {
        std::stack<char> charStack;

        for (const char &ch : s) {
            bool popped = false;
            while (!charStack.empty() && ch == charStack.top()) {
                charStack.pop();
                popped = true;
            }

            if (!popped)
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