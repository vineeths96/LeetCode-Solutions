class Solution {
public:
    std::vector<std::vector<int>> twoSum(const std::vector<int> &nums, long long target, int index) {
        int start = index;
        int end = nums.size() - 1;

        std::vector<std::vector<int>> tuples;
        while (start < end) {
            int currentSum = nums[start] + nums[end];
            if (currentSum < target)
                start++;
            else if (currentSum > target)
                end--;
            else {
                tuples.push_back({nums[start], nums[end]});
                start++;
                end--;

                while (start < end && nums[start] == nums[start-1])
                    start++;

                while (start < end && nums[end] == nums[end+1])
                    end--;
            }
        }

        return tuples;
    }

    std::vector<std::vector<int>> kSum(const std::vector<int> nums, long long target, int index, int k) {
        std::vector<std::vector<int>> kGroups;
        if (index == nums.size())
            return kGroups;

        if (target / k < nums[index] || target / k > nums[nums.size() - 1])
            return kGroups;

        if (k == 2)
            return twoSum(nums, target, index);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i-1])
                continue;

            auto subsets = kSum(nums, target - nums[i], i + 1, k - 1);
            for (auto subset : subsets) {
                subset.push_back(nums[i]);
                kGroups.push_back(subset);
            }
        }

        return kGroups;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        return kSum(nums, static_cast<long long>(target), 0, 4);    
    }
};