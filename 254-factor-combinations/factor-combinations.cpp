class Solution {
    std::vector<std::vector<int>> factorSet;

    void getFactorsRecursive(int n, int start, std::vector<int> &currentFactors) {
        for (int i = start; i <= std::sqrt(n); i++) {
            if (n % i == 0) {
                currentFactors.push_back(i);
                currentFactors.push_back(n / i);
                factorSet.push_back(currentFactors);
                currentFactors.pop_back();
                
                getFactorsRecursive(n / i, i, currentFactors);
                currentFactors.pop_back();
            }
        }
    }

public:
    vector<vector<int>> getFactors(int n) {
        std::vector<int> currentFactors;
        getFactorsRecursive(n, 2, currentFactors);
        return factorSet;
    }
};