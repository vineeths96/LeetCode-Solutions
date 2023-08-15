/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        std::stack<ListNode*> monotonicStack;

        for (ListNode *current = head; current != nullptr; current = current->next) {
            while (!monotonicStack.empty() && current->val > monotonicStack.top()->val)
                monotonicStack.pop();

            monotonicStack.push(current);
        }

        ListNode *next = nullptr;
        ListNode *current = monotonicStack.top();
        while (!monotonicStack.empty()) {
            current = monotonicStack.top();
            monotonicStack.pop();
            current->next = next;
            next = current;
        }

        return current;
    }
};