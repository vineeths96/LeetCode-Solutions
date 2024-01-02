class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int sign = 1;

        int index = 0;
        while (s[index] == ' ')
            index++;

        if (s[index] == '+' || s[index] == '-')
            sign = s[index++] == '+' ? 1 : -1;

        while (std::isdigit(s[index])) {
            char ch = s[index++];
            if (num < (std::numeric_limits<int>::min() + (ch - '0')) / 10)
                num = std::numeric_limits<int>::min();
            else
                num = num * 10 - (ch - '0');
        }

        if (sign > 0)
            num = num == std::numeric_limits<int>::min() ? std::numeric_limits<int>::max() : -1 * num;

        return num;
    }
};