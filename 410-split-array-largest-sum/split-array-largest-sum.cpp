class Solution {
    bool checkPartitions(const std::vector<int> &nums, int mid, int k) {
        int partitions = 1;
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (currentSum + nums[i] <= mid)
                currentSum += nums[i];
            else {
                currentSum = nums[i];
                partitions++;
            }                
        }

        return partitions <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        auto maxElement = std::max_element(nums.begin(), nums.end());

        int left = *maxElement;
        int right = sum;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (checkPartitions(nums, mid, k))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};