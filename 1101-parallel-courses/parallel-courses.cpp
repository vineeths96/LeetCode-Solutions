class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        std::unordered_map<int, int> inDegree;
        std::unordered_map<int, std::vector<int>> graph;

        for (int i = 1; i <= n; i++) {
            inDegree[i] = 0;
            graph[i] = std::vector<int>();
        }

        for (const auto &relation : relations) {
            int parent = relation[0];
            int child = relation[1];
            graph[parent].push_back(child);
            inDegree[child]++;
        }

        std::queue<int> topoSortQueue;
        for (const auto &kvPair : inDegree)
            if (kvPair.second == 0)
                topoSortQueue.push(kvPair.first);

        int semesterCount = 0;
        int totalCourses = 0;
        while (!topoSortQueue.empty()) {
            semesterCount++;

            int courseSize = topoSortQueue.size();
            for (int i = 0; i < courseSize; i++) {
                int vertex = topoSortQueue.front();
                topoSortQueue.pop();

                totalCourses++;

                for (const int &neighbour : graph[vertex]) {
                    inDegree[neighbour]--;
                    if (inDegree[neighbour] == 0)
                        topoSortQueue.push(neighbour);
                }
            }
        }

        return totalCourses == inDegree.size() ? semesterCount : -1;
    }
};