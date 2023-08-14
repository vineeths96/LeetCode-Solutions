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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;

        int numNodes = 0;
        for (ListNode *current = head; current != nullptr; current = current->next)
            numNodes++;

        ListNode *previous = nullptr;
        ListNode *current = head;
        ListNode *currentGroupStart = head;
        for (int group = 0; group < numNodes / k; group++) {
            ListNode* subListPrevious = nullptr;
            for (int i = 0; i < k; i++) {
                ListNode *currentNext = current->next;
                current->next = subListPrevious;
                subListPrevious = current;
                current = currentNext;
            }

            if (previous == nullptr) {
                previous = head;
                head = subListPrevious;
            } else {
                previous->next = subListPrevious;
                previous = currentGroupStart;
            }

            currentGroupStart->next = current;
            currentGroupStart = current;
        }

        return head;
    }
};