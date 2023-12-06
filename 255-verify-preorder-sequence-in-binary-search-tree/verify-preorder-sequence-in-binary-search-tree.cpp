class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        std::stack<int> monotonicStack;

        int lowerBound = std::numeric_limits<int>::min();
        for (int i = 0; i < preorder.size(); i++) {
            while (!monotonicStack.empty() && monotonicStack.top() < preorder[i]) {
                lowerBound = monotonicStack.top();
                monotonicStack.pop();
            }

            if (preorder[i] < lowerBound)
                return false;

            monotonicStack.push(preorder[i]);
        }

        return true;
    }
};