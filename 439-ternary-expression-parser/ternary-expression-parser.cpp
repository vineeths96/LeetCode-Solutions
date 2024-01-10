class Solution {
public:
    string parseTernary(string expression) {
        std::string charStack;

        for (int i = expression.size() - 1; i >= 0; i--) {
            if (!charStack.empty() && charStack.back() == '?') {
                charStack.pop_back();

                char trueCase = charStack.back();
                charStack.pop_back();

                charStack.pop_back();
                char falseCase = charStack.back();
                charStack.pop_back();

                if (expression[i] == 'T')
                    charStack.push_back(trueCase);
                else
                    charStack.push_back(falseCase);
            } else
                charStack.push_back(expression[i]);
        }

        return charStack;
    }
};