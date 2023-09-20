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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0);
        ListNode *previous = head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                previous->next = list1;
                list1 = list1->next;
            } else {
                previous->next = list2;
                list2 = list2->next;
            }

            previous = previous->next;
        }

        if (list1 == nullptr) previous->next = list2;
        if (list2 == nullptr) previous->next = list1;

        return head->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        for (int interval = 1; interval < lists.size(); interval *= 2)
            for (int i = 0; i < lists.size() - interval; i += interval * 2)
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);

        return lists[0];
    }
};