class Solution {
    std::vector<int> rank;
    std::vector<int> parent;

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);

        return parent[node];
    }

    bool unionSet(int nodeX, int nodeY) {
        int rootX = find(nodeX);
        int rootY = find(nodeY);

        if (rootX == rootY)
            return false;
        
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            rank[rootX]++;
            parent[rootY] = rootX;
        }

        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        rank = std::vector<int>(edges.size() + 1);
        parent = std::vector<int>(edges.size() + 1);

        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;

        for (const auto &edge : edges) 
            if (!unionSet(edge[0], edge[1]))
                return edge;

        return {};
    }
};