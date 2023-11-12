class Solution {
    std::unordered_map<std::string, bool> dpMap;

    bool isInterleaveRecursive(const std::string &s1, const std::string &s2, const std::string &s3, int index1, int index2, int index3) {
        if (index3 == s3.size())
            return index1 == s1.size() && index2 == s2.size();

        std::stringstream dpKey;
        dpKey << index1 << "|" << index2 << "|" << index3;
        if (dpMap.find(dpKey.str()) != dpMap.end())
            return dpMap[dpKey.str()];

        bool result = false;
        if (index1 < s1.size() && s3[index3] == s1[index1])
            result = result | isInterleaveRecursive(s1, s2, s3, index1 + 1, index2, index3 + 1);

        if (index2 < s2.size() && s3[index3] == s2[index2])
            result = result | isInterleaveRecursive(s1, s2, s3, index1, index2 + 1, index3 + 1);

        return dpMap[dpKey.str()] = result;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleaveRecursive(s1, s2, s3, 0, 0, 0);
    }
};