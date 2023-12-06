class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = -1;
        for (int i = 0; i < nums.size(); i++) {
            maxJump = std::max(maxJump, i + nums[i]);

            if (maxJump >= nums.size() - 1) return true;
            else if (maxJump == i) return false;
        }

        return false;
    }
};