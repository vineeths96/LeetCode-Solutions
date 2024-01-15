class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        std::string formattedString;

        int charsInGroup = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-')
                continue;

            formattedString.push_back(std::toupper(s[i]));
            if (++charsInGroup % k == 0)
                formattedString.push_back('-');
        }

        if (!formattedString.empty() && formattedString.back() == '-')
            formattedString.pop_back();

        std::reverse(formattedString.begin(), formattedString.end());
        return formattedString;
    }
};