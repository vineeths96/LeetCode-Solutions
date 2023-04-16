class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> numTracker;

        for (const int& num : nums) {
            if (numTracker.find(num) != numTracker.end())
                return true;

            numTracker.insert(num);
        }

        return false;
    }
};