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
    bool isPalindrome(ListNode* head) {
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;

        while (fastPointer != nullptr && fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        if (fastPointer != nullptr)
            slowPointer = slowPointer->next;

        ListNode *current = slowPointer;
        ListNode *previous = nullptr;
        while (current != nullptr) {
            ListNode *currentNext = current->next;
            current->next = previous;
            previous = current;
            current = currentNext;
        }

        current = head;
        while (previous != nullptr) {
            if (current->val != previous->val)
                return false;

            current = current->next;
            previous = previous->next;
        }

        return true;
    }
};