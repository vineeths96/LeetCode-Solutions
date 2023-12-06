class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        std::stack<int> monotonicStack;

        int index = 0;
        int lowerBound = std::numeric_limits<int>::min();
        for (int i = 0; i < preorder.size(); i++) {
            while (index > 0 && preorder[index - 1] < preorder[i]) {
                lowerBound = preorder[index - 1];
                index--;
            }

            if (preorder[i] < lowerBound)
                return false;

            preorder[index] = preorder[i];
            index++;
        }

        return true;
    }
};