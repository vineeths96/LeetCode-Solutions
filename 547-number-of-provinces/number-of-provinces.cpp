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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numNodes = isConnected.size();
        int numProvinces = numNodes;
        rank = std::vector<int>(numNodes, 1);
        parent = std::vector<int>(numNodes);

        for (int i = 0; i < numNodes; i++)
            parent[i] = i;

        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (isConnected[i][j] && unionSet(i, j))
                    numProvinces--;
            }
        }

        return numProvinces;
    }
};