class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        std::vector<int> sequence;
        for (const int num : nums) {
            if (sequence.empty() || sequence.back() < num)
                sequence.push_back(num);
            else {
                int pos = std::lower_bound(sequence.begin(), sequence.end(), num) - sequence.begin();
                sequence[pos] = num;
            }

            if (sequence.size() == 3)
                return true;
        }

        return false;
    }
};