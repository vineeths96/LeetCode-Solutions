class Solution {
    std::vector<std::vector<int>> subsetsSet;

    void recursionHelper(const std::vector<int> &nums, int currentIndex, std::vector<int> &currentVector) {
        if (currentIndex == nums.size()) {
            subsetsSet.push_back(currentVector);
            return;
        }

        currentVector.push_back(nums[currentIndex]);
        recursionHelper(nums, currentIndex + 1, currentVector);
        currentVector.pop_back();
        recursionHelper(nums, currentIndex + 1, currentVector);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> currentVector;
        recursionHelper(nums, 0, currentVector);
        return subsetsSet;
    }
};