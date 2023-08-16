class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int distance = INT_MAX;
        int firstIndex = -1, secondIndex = -1;

        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1)
                firstIndex = i;
            else if (wordsDict[i] == word2)
                secondIndex = i;

            if (firstIndex != -1 && secondIndex != -1)
                distance = std::min(distance, std::abs(firstIndex - secondIndex));
        }

        return distance;
    }
};