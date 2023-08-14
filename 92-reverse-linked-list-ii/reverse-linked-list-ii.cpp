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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr)
            return head;

    	ListNode* previous = nullptr;
        ListNode* current = head;
        for (int i = 1; i < left; i++) {
            previous = current;
            current = current->next;
        }

        ListNode* subListPrevious = nullptr;
        for (int i = left; i <= right; i++) {
            ListNode* currentNext = current->next;
            current->next = subListPrevious;
            subListPrevious = current;
            current = currentNext;
        }

        if (previous == nullptr) {
            head->next = current;
            head = subListPrevious;
        } else {
            previous->next->next = current;
            previous->next = subListPrevious;
        }

        return head;
    }
};