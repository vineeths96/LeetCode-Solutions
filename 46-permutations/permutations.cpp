class Solution {
    std::vector<std::vector<int>> permutations;

    void recursionHelper(std::vector<int> &nums, int currentIndex) {
        if (currentIndex == nums.size()) {
            permutations.push_back(nums);
            return;
        }

        for (int i = currentIndex; i < nums.size(); i++) {
            std::swap(nums[currentIndex], nums[i]);
            recursionHelper(nums, currentIndex + 1);
            std::swap(nums[currentIndex], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        recursionHelper(nums, 0);
        return permutations;
    }
};