class Solution {
    std::unordered_set<std::string> uniqueStrings; 

    int maxUniqueSplitRecursive(std::string s, int currentIndex) {
        if (currentIndex == s.size())
            return uniqueStrings.size();

        int count = 0;
        for (int i = currentIndex; i < s.size(); i++) {
            std::string subStr = s.substr(currentIndex, i - currentIndex + 1);
            if (uniqueStrings.find(subStr) == uniqueStrings.end()) {
                uniqueStrings.insert(subStr);
                count = std::max(count, maxUniqueSplitRecursive(s, i + 1));
                uniqueStrings.erase(subStr);
            }
        }

        return count;
    }

public:
    int maxUniqueSplit(string s) {
       return maxUniqueSplitRecursive(s, 0); 
    }
};