class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numsSet;
        for (const int &num : nums)
            numsSet.insert(num);

        int maxLength = 0;
        for (const int &num : nums) {
            if (numsSet.find(num - 1) == numsSet.end()) {
                int currentNum = num;
                int currentMaxLength = 0;

                while (numsSet.find(currentNum) != numsSet.end()) {
                    currentNum++;
                    currentMaxLength++;
                }

                maxLength = std::max(maxLength, currentMaxLength);
            }
        }

        return maxLength;
    }
};