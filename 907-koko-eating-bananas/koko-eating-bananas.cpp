class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas = 0;
        for (const int &pile : piles)
            maxBananas = std::max(maxBananas, pile);

        int left = 1;
        int right = maxBananas;
        while (left < right) {
            int mid = left + (right - left) / 2;

            int hoursToEat = 0;
            for (const int &pile : piles)
                hoursToEat += std::ceil(static_cast<double>(pile) / mid); 

            if (hoursToEat <= h)   
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};