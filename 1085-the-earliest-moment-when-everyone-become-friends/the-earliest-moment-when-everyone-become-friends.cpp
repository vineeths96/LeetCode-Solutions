class Solution {
    class DSU {
        std::vector<int> parent;
        std::vector<int> rank;

    public:
        DSU(int n) {
            parent = std::vector<int>(n, 0);
            rank = std::vector<int>(n, 1);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int node) {
            if (parent[node] != node)
                parent[node] = find(parent[node]);

            return parent[node];
        }

        bool merge(int nodeX, int nodeY) {
            int rootX= find(nodeX);
            int rootY= find(nodeY);

            if (rootX == rootY)
                return false;

            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootY] < rank[rootX])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }

            return true;
        }
    };

public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        DSU dsu = DSU(n);
        std::sort(logs.begin(), logs.end(), [](const std::vector<int> &A, const std::vector<int> &B) {
            return A[0] < B[0];
        });

        for (const auto &log : logs) {
            if (dsu.merge(log[1], log[2]) && --n == 1)
                return log[0];
        }

        return -1;
    }
};