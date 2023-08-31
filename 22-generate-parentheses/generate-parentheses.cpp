class Solution {
    std::vector<std::string> parentheses;

    void recursionHelper(std::string &str, int n, int currentIndex, int opening, int closing) {
        if (currentIndex == 2 * n) {
            if (opening == closing) parentheses.push_back(str);
            return;
        }

        if (closing > opening) return;
        
        str.push_back('(');
        recursionHelper(str, n, currentIndex + 1, opening + 1, closing);
        str.pop_back();
        
        str.push_back(')');
        recursionHelper(str, n, currentIndex + 1, opening, closing + 1);
        str.pop_back();
    }


public:
    vector<string> generateParenthesis(int n) {
        std::string str;
        recursionHelper(str, n, 0, 0, 0);
        return parentheses;
    }
};