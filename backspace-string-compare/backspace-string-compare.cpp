class Solution {
public:
    int getValidCharIndex(std::string str, int index) {
        int backspaceCount = 0;
        while (index >= 0) {
            if (str[index] == '#')
                backspaceCount++;
            else {
                if (backspaceCount == 0)
                    break;

                backspaceCount--;
            }
            index--;
        }

        return index;
    }

    bool backspaceCompare(string s, string t) {
        int firstIndex = s.size() - 1;
        int secondIndex = t.size() - 1;

        while (firstIndex >= 0 || secondIndex >= 0) {
            firstIndex = getValidCharIndex(s, firstIndex);
            secondIndex = getValidCharIndex(t, secondIndex);

            if (firstIndex < 0 && secondIndex < 0)
                return true;
            else if (firstIndex < 0 || secondIndex < 0)
                return false;
            else if (s[firstIndex] != t[secondIndex])
                return false;
            else {
                firstIndex--;
                secondIndex--;
            }     
        }

        return true;
    }
};