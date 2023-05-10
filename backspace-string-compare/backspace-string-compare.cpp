class Solution {
public:
    bool backspaceCompare(string s, string t) {
        std::string S, T;

        for (const char &ch : s) {
            if (ch == '#') {
                if (S.size())
                    S.erase(S.length() - 1);
            } else
                S.push_back(ch);
        }

        for (const char &ch : t) {
            if (ch == '#') {
                if (T.size())
                    T.erase(T.length() - 1);
            } else
                T.push_back(ch);
        }

        return S == T;
    }
};