class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0;
       int cumulativeProfit = 0;
       for (int i = 1; i < prices.size(); i++) {
           cumulativeProfit += prices[i] - prices[i - 1];
           profit = std::max(profit, cumulativeProfit);

           cumulativeProfit = cumulativeProfit < 0 ? 0 : cumulativeProfit;           
       }

        return profit;
    }
};