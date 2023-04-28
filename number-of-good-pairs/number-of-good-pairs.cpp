class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> indexTracker;

        for (int i = 0; i < nums.size(); i++) 
            indexTracker[nums[i]].push_back(i);

        int count = 0;
        for (const auto& kv : indexTracker) {
            int numIndices = kv.second.size();
            count += numIndices * (numIndices - 1) / 2;
        }

        return count;
    }
};