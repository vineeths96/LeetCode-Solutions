class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        std::vector<int> color(graph.size(), -1);

        std::stack<int> dfsStack;
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] != -1)
                continue;

            dfsStack.push(i);
            color[i] = 0;
            while (!dfsStack.empty()) {
                int node = dfsStack.top();
                dfsStack.pop();

                for (const int &neighbour : graph[node])  {
                    if (color[neighbour] == -1) {
                        dfsStack.push(neighbour);
                        color[neighbour] = 1 ^ color[node];
                    } else if (color[neighbour] == color[node])
                        return false;
                }
            }
        }

        return true;
    }
};