class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;

        std::vector<int> dpVector(n + 1, -1);
        dpVector[0] = 0;
        dpVector[1] = 1;

        for (int i = 2; i < dpVector.size(); i++)
            dpVector[i] = dpVector[i - 1] + dpVector[i - 2];

        return dpVector[n];
    }
};