class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, int> inDegrees;
        std::unordered_map<int, std::vector<int>> graph;

        for (int i = 0; i < n; i++) {
            inDegrees[i] = 0;
            graph[i] = std::vector<int>();
        }

        for (const auto &edge : edges) {
            int fnode = edge[0];
            int snode = edge[1];

            inDegrees[fnode]++;
            inDegrees[snode]++;
            graph[fnode].push_back(snode);
            graph[snode].push_back(fnode);
        }

        std::queue<int> topoSortQueue;
        for (const auto &vdPair : inDegrees)
            if (vdPair.second <= 1)
                topoSortQueue.push(vdPair.first);

        while (n > 2) {
            int leavesSize = topoSortQueue.size();
            n = n - leavesSize;

            for (int i = 0; i < leavesSize; i++) {
                int vertex = topoSortQueue.front();
                topoSortQueue.pop();

                for (const auto &neighbour : graph[vertex]) {
                    inDegrees[neighbour]--;
                    if (inDegrees[neighbour] == 1)
                        topoSortQueue.push(neighbour);
                }
            }
        }

        std::vector<int> roots;
        while (!topoSortQueue.empty()) {
            roots.push_back(topoSortQueue.front());
            topoSortQueue.pop();
        }

        return roots.size() ? roots : std::vector<int>({0});
    }
};