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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;

        int numNodes = 0;
        for (ListNode *current = head; current != nullptr; current = current->next)
            numNodes++;

        k = k % numNodes;
        if (k == 0) return head;

        ListNode *previous = nullptr;
        ListNode *current = head;
        for (int i = 0; i < numNodes - k; i++) {
            previous = current;
            current = current->next;
        }

        previous->next = nullptr;
        ListNode* crawler = current;
        while (crawler->next != nullptr)
            crawler = crawler->next;

        crawler->next = head;
        head = current;

        return head;
    }
};