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
    struct Compare {
        bool operator()(const ListNode *A, const ListNode *B) {
            return A->val > B->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;
        for (const auto &head : lists) 
            if (head != nullptr)
                minHeap.push(head);

        ListNode *head = nullptr;
        ListNode *previous = nullptr;
        while (!minHeap.empty()) {
            ListNode *top = minHeap.top();
            minHeap.pop();

            if (head == nullptr) head = top;
            else previous->next = top;

            if (top->next != nullptr) 
                minHeap.push(top->next);

            previous = top;
        }

        return head;
    }
};