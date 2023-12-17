class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstNum = std::numeric_limits<int>::max();
        int secondNum = std::numeric_limits<int>::max();

        for (const int num : nums) {
            if (num <= firstNum)
                firstNum = num;
            else if (num <= secondNum)
                secondNum = num;
            else
                return true;
        }

        return false;
    }
};