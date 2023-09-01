class Solution {
    std::vector<std::vector<int>> uniqueSubsets;

    void recursionHelper(const std::vector<int> &nums, int currentIndex, std::vector<int> &currentSubset) {
        uniqueSubsets.push_back(currentSubset);

        for (int i = currentIndex; i < nums.size(); i++) {
            if (i > currentIndex && nums[i] == nums[i-1])
                continue;

            currentSubset.push_back(nums[i]);
            recursionHelper(nums, i + 1, currentSubset);
            currentSubset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<int> currentSubset;
        recursionHelper(nums, 0, currentSubset);
        return uniqueSubsets;
    }
};