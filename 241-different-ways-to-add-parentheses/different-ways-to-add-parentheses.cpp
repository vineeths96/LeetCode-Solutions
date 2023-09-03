class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        std::vector<int> results;

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                auto firstHalfResults = diffWaysToCompute(expression.substr(0, i));
                auto secondHalfResults = diffWaysToCompute(expression.substr(i + 1, expression.size()));

                for (const int &first : firstHalfResults) {
                    for (const int &second : secondHalfResults) {
                        switch (expression[i]) {
                            case '+': results.push_back(first + second); break;
                            case '-': results.push_back(first - second); break;
                            case '*': results.push_back(first * second); break;
                        }
                    }
                }
            }
        }
    
        if (results.empty()) results.push_back(std::stoi(expression));

        return results;
    }
};