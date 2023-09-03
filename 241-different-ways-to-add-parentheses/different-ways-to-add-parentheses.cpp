class Solution {
    std::unordered_map<std::string, std::vector<int>> dpMap;
public:
    vector<int> diffWaysToCompute(string expression) {
        if (dpMap.find(expression) != dpMap.end())
            return dpMap[expression];

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
        dpMap[expression] = results;
        
        return results;
    }
};