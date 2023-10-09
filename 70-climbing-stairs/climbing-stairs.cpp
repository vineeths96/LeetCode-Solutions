class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        std::vector<int> dpVector(n + 1, -1);
        dpVector[1] = 1;
        dpVector[2] = 2;
        for (int i = 3; i < dpVector.size(); i++) 
            dpVector[i] = dpVector[i - 1] + dpVector[i - 2];

        return dpVector[n];
    }
};