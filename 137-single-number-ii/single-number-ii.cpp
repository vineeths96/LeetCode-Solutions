class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0;
        int seenTwice = 0;

        for (const int &num : nums) {
            seenOnce = (seenOnce ^ num) & ~seenTwice;
            seenTwice = (seenTwice ^ num) & ~seenOnce;
        }    

        return seenOnce;
    }
};