class Solution {
public:
    string alienOrder(vector<string>& words) {
        std::unordered_map<char, int> inDegrees;
        std::unordered_map<char, std::vector<char>> adjList;

        for (const auto &word : words) {
            for (const char &ch : word) {
                inDegrees[ch] = 0;
                adjList[ch] = std::vector<char>();
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            std::string firstWord = words[i];
            std::string secondWord = words[i + 1];

            if (firstWord.size() > secondWord.size() && firstWord.find(secondWord) == 0)
                return "";

            for (int j = 0; j < firstWord.size(); j++) {
                if (j < secondWord.size() && firstWord[j] != secondWord[j]) {
                    inDegrees[secondWord[j]]++;
                    adjList[firstWord[j]].push_back(secondWord[j]);
                    break;
                }
            }
        }

        std::queue<char> topoSortQueue;
        for (const auto &kvPair : inDegrees)
            if (kvPair.second == 0)
                topoSortQueue.push(kvPair.first);

        std::string topoSort;
        while (!topoSortQueue.empty()) {
            char vertex = topoSortQueue.front();
            topoSortQueue.pop();

            topoSort.push_back(vertex);
            for (const char &neighbour : adjList[vertex]) {
                inDegrees[neighbour]--;
                if (inDegrees[neighbour] == 0)
                    topoSortQueue.push(neighbour);
            }
        }

        return topoSort.size() == inDegrees.size() ? topoSort : "";
    }
};