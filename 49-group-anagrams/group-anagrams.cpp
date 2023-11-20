class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groupStrings; 

        for (const std::string &str : strs) {
            std::map<char, int> freqCount;
            for (const char &ch : str)
                freqCount[ch]++;

            std::string hash = "|";
            for (const auto &kvPair : freqCount)
                hash += std::to_string(kvPair.first) + "|" + std::to_string(kvPair.second) + "|";

            groupStrings[hash].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto &kvPair : groupStrings) {
            result.push_back({});
            for (const auto &str : kvPair.second)
                result.back().push_back(str);
        }

        return result;
    }
};