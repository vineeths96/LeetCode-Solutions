/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;
        bool cycleFound = false;

        while (fastPointer != nullptr && fastPointer->next != nullptr) {          
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;

            if (slowPointer == fastPointer) {
                cycleFound = true;
                break;
            }
        }

        if (!cycleFound) 
            return nullptr;

        fastPointer = head;
        while (slowPointer != fastPointer) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }

        return slowPointer;
    }
};