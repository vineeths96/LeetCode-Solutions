class Solution {
    std::unordered_map<int, int> dpMap;

public:
    int numTrees(int n) {        
        if (n == 0 || n == 1) 
            return  1;

        if (dpMap.find(n) != dpMap.end())
            return dpMap[n];

        int trees = 0;
        for (int i = 1; i <= n; i++)
            trees += numTrees(i - 1) * numTrees(n - i);

        dpMap[n] = trees;
        
        return trees;
    }
};