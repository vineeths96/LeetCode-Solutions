class Solution {
    class DSU {
        std::vector<int> rank;
        std::vector<int> parent;

    public:
        DSU(int n) {
            rank = std::vector<int>(n, 1);
            parent = std::vector<int>(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int node) {
            if (parent[node] != node)
                parent[node] = find(parent[node]);

            return parent[node];
        }

        bool merge(int nodeX, int nodeY) {
            int groupX = find(nodeX);
            int groupY = find(nodeY);

            if (groupX == groupY)
                return false;

            if (rank[groupX] < rank[groupY])
                parent[groupX] = groupY;
            else if (rank[groupX] > rank[groupY])
                parent[groupY] = groupX;
            else {
                rank[groupX]++;
                parent[groupY] = groupX;
            }

            return true;
        }
    };
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU unionFind = DSU(n);

        int numComponents = n;
        for (const auto &edge : edges)
            if (unionFind.merge(edge[0], edge[1]))
                numComponents--;
            else
                return false;
        
        return numComponents == 1;
    }
};