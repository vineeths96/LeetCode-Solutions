class Solution {
    std::vector<std::vector<int>> dpVector;

    int minDistanceRecursive(const std::string &word1, const std::string &word2, int index1, int index2) {
        if (index1 == word1.size() && index2 == word2.size())
            return 0;

        if (index1 == word1.size())
            return word2.size() - index2;

        if (index2 == word2.size())
            return word1.size() - index1;

        if (dpVector[index1][index2] != -1)
            return dpVector[index1][index2];

        int distance = std::numeric_limits<int>::max();
        if (word1[index1] == word2[index2])
            distance = minDistanceRecursive(word1, word2, index1 + 1, index2 + 1);
        else {
            distance = std::min(distance, 1 + minDistanceRecursive(word1, word2, index1 + 1, index2 + 1));
            distance = std::min(distance, 1 + minDistanceRecursive(word1, word2, index1, index2 + 1));
            distance = std::min(distance, 1 + minDistanceRecursive(word1, word2, index1 + 1, index2));
        }

        return dpVector[index1][index2] = distance;
    }

public:
    int minDistance(string word1, string word2) {
        dpVector = std::vector<std::vector<int>>(word1.size(), std::vector<int>(word2.size(), -1));
        return minDistanceRecursive(word1, word2, 0, 0);
    }
};