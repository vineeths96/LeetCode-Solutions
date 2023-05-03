class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int smallerCount = 0;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end) {
                int currentSum = nums[i] + nums[start] + nums[end];

                if (currentSum >= target) {
                    end--;
                    continue;
                }

                smallerCount += (end - start);
                start++;
            }
        }

        return smallerCount;
    }
};