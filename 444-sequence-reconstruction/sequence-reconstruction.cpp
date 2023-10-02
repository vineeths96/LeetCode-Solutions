class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        std::unordered_map<int, int> inDegrees;
        std::unordered_map<int, std::vector<int>> adjList;

        for (const auto &sequence : sequences) {
            for (const int &num : sequence) {
                inDegrees[num] = 0;
                adjList[num] = std::vector<int>();
            }
        }

        for (const auto &sequence : sequences) {
            for (int i = 0; i < sequence.size() - 1; i++) {
                inDegrees[sequence[i+1]]++;
                adjList[sequence[i]].push_back(sequence[i+1]);
            }
        }

        std::queue<int> topoSortQueue;
        for (const auto &kvPair : inDegrees)
            if (kvPair.second == 0)
                topoSortQueue.push(kvPair.first);

        std::vector<int> topoSort;
        while (!topoSortQueue.empty()) {
            if (topoSortQueue.size() > 1) 
                return false;

            int vertex = topoSortQueue.front();
            topoSortQueue.pop();

            topoSort.push_back(vertex);
            for (const int &neighbour : adjList[vertex]) {
                inDegrees[neighbour]--;
                if (inDegrees[neighbour] == 0)  
                    topoSortQueue.push(neighbour);
            }
        }      

        return topoSort == nums;
    }
};