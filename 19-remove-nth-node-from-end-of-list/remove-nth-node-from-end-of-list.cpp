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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n == 0)
            return head;

        ListNode *dummy = new ListNode(-1, head);
        ListNode *back = dummy;
        ListNode *front = dummy;

        for (int i = 0; i <= n; i++)
            front = front->next;

        while (front != nullptr) {
            back = back->next;
            front = front->next;
        }

        back->next = back->next->next;
        return dummy->next;
    }
};