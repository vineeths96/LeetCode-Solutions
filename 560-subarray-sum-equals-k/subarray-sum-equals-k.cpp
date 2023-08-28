class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int numArrays = 0;
        int currentPrefixSum = 0;
        std::unordered_map<int, int> prefixSum;
        prefixSum.insert({0, 1});

        for (const int &num : nums) {
            currentPrefixSum += num;

            if (prefixSum.find(currentPrefixSum - k) != prefixSum.end())
                numArrays += prefixSum[currentPrefixSum - k];

            prefixSum[currentPrefixSum]++;
        }

        return numArrays;
    }
};