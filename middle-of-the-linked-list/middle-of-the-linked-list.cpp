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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode *slowPointer = head;
        ListNode *fastPointer = head->next;

        while (fastPointer != nullptr) {
            slowPointer = slowPointer->next;

            if (fastPointer->next != nullptr)
                fastPointer = fastPointer->next->next;
            else
                break;
        }

        return slowPointer;
    }
};