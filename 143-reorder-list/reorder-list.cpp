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
    void reorderList(ListNode* head) {
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;

        while (fastPointer != nullptr && fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        ListNode *current = slowPointer;
        ListNode *previous = nullptr;
        while (current != nullptr) {
            ListNode *currentNext = current->next;
            current->next = previous;
            previous = current;
            current = currentNext;
        }

        current = head;
        while (previous->next != nullptr) {
            ListNode *currentNext = current->next;
            current->next = previous;
            ListNode *previousNext = previous->next;
            previous->next = currentNext;

            current = currentNext;
            previous = previousNext;
        }
    }
};