class Solution {
    std::vector<std::vector<int>> combinations;

    void combinationSumRecursive(const std::vector<int> &candidates, int target, int currentIndex, std::vector<int> &currentVector) {
        if (target == 0)
            combinations.push_back(currentVector);
        else if (target < 0)
            return;

        for (int i = currentIndex; i < candidates.size(); i++) {
            currentVector.push_back(candidates[i]);
            target -= candidates[i];
            combinationSumRecursive(candidates, target, i, currentVector);
            target += candidates[i];
            currentVector.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<int> currentVector;
        combinationSumRecursive(candidates, target, 0, currentVector);
        return combinations;
    }
};