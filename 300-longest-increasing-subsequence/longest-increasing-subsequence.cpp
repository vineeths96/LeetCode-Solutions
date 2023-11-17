class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> subSequence;

        for (const int &num : nums) {
            if (subSequence.empty() || subSequence.back() < num)
                subSequence.push_back(num);
            else {
                int ind = std::lower_bound(subSequence.begin(), subSequence.end(), num) - subSequence.begin();
                subSequence[ind] = num;
            }
        }
        
        return subSequence.size();
    }
};