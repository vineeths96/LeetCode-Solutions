class Solution {
    std::vector<std::vector<int>> combinations;

    void combineRecursive(int n, int k, int currentNum, std::vector<int> &currentCombination) {
        if (currentCombination.size() == k) {
            combinations.push_back(currentCombination);
            return;
        }

        for (int i = currentNum; i <= n; i++) {
            currentCombination.push_back(i);
            combineRecursive(n, k, i + 1, currentCombination);
            currentCombination.pop_back();
        }
    } 

public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<int> currentCombination;
        combineRecursive(n, k, 1, currentCombination);

        return combinations;
    }
};