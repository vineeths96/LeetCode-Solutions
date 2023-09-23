class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> inDegrees(numCourses, 0);
        std::vector<std::vector<int>> adjList(numCourses);

        for (const auto &edge : prerequisites) {
            inDegrees[edge[0]]++;
            adjList[edge[1]].push_back(edge[0]);
        }

        std::queue<int> topoSortQueue;
        for (int vertex = 0; vertex < inDegrees.size(); vertex++)
            if (inDegrees[vertex] == 0)
                topoSortQueue.push(vertex);

        std::vector<int> topoSort;
        while (!topoSortQueue.empty()) {
            int vertex = topoSortQueue.front();
            topoSortQueue.pop();

            topoSort.push_back(vertex);
            for (const int &neighbour : adjList[vertex]) {
                inDegrees[neighbour]--;
                if (inDegrees[neighbour] == 0)
                    topoSortQueue.push(neighbour);
            }
        }

        return topoSort.size() == numCourses ? topoSort : std::vector<int>();
    }
};