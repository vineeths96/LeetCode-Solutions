class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minVal = std::numeric_limits<int>::max();
       int maxProfit = 0;
       for (int i = 0; i < prices.size(); i++) {
           minVal = std::min(minVal, prices[i]);
           maxProfit = std::max(maxProfit, prices[i] - minVal);
       }

        return maxProfit;
    }
};