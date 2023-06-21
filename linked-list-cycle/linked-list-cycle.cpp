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
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;

        ListNode *slowCrawler = head;
        ListNode *fastCrawler = head->next;

        while (fastCrawler != slowCrawler) {
            if (fastCrawler == nullptr || fastCrawler->next == nullptr)
                return false;

            slowCrawler = slowCrawler->next;
            fastCrawler = fastCrawler->next->next;
        }

        return true;
    }
};