class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int bestDiff = INT_MAX;
        int bestSum;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {            
            int start = i + 1;
            int end = nums.size() - 1;

            while(start < end) {
                int currentSum = nums[i] + nums[start] + nums[end];
                int currentDiff = std::abs(target - currentSum);
 
                if (currentDiff < bestDiff) {
                    bestDiff = currentDiff;
                    bestSum = currentSum;
                }

                if (currentSum > target)
                    end--;
                else if (currentSum < target)
                    start++;
                else
                    break;
            }

        }

        return bestSum;
    }
};