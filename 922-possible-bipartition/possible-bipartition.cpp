class Solution {
    int WHITE = 0;
    int RED = -1;
    int BLUE = 1;

    bool dfsColor(const std::vector<std::vector<int>> &graph, std::vector<int> &color, int vertex) {
        bool result = true;
        for (const int &neighbour : graph[vertex]) {
            if (color[neighbour] == color[vertex])
                return false;
            else if (color[neighbour] == WHITE) {
                color[neighbour] = -1 * color[vertex];
                result = result && dfsColor(graph, color, neighbour);
            }
        }

        return result;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
        for (const auto &dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }

        std::vector<int> color(n + 1, WHITE);
        bool result = true;
        for (int i = 1; i <= n; i++) {
            if (color[i] == WHITE) {
                color[i] = RED;
                result = result && dfsColor(graph, color, i);
            }
        }

        return result;
    }
};