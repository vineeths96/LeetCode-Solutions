class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, int> inDegrees;
        std::unordered_map<int, std::vector<int>> adjList;

        for (int i = 0; i < numCourses; i++) {
            inDegrees[i] = 0;
            adjList[i] = {};
        }

        for (const auto &edge : prerequisites) {
            inDegrees[edge[0]]++;
            adjList[edge[1]].push_back(edge[0]);
        }

        std::queue<int> topoSortQueue;
        for (const auto &vertexDegreePair : inDegrees)
            if (vertexDegreePair.second == 0)
                topoSortQueue.push(vertexDegreePair.first);
        
        std::vector<int> topoSort;
        while (!topoSortQueue.empty()) {
            int vertex = topoSortQueue.front();
            topoSortQueue.pop();

            topoSort.push_back(vertex);
            for (const auto &edge : adjList[vertex]) {
                inDegrees[edge]--;
                if (inDegrees[edge] == 0)
                    topoSortQueue.push(edge);
            }
        }
        
        return topoSort.size() == numCourses; 
    }
};