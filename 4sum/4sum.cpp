class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> quadruplets;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j-1])
                    continue;

                int start = j + 1;
                int end = nums.size() - 1;

                while (start < end) {
                    long currentSum = static_cast<long>(nums[i]) + static_cast<long>(nums[j])
                                      + static_cast<long>(nums[start]) + static_cast<long>(nums[end]);

                    if (currentSum < target)
                        start++;
                    else if (currentSum > target)
                        end--;
                    else {
                        quadruplets.push_back({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;

                        while (start < end && nums[start] == nums[start-1])
                            start++;

                        while (start < end && nums[end] == nums[end+1])
                            end--;
                    }
                }
            }
        }

        return quadruplets;
    }
};