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

        while (fastPointer != nullptr && fastPointer->next != nullptr) {          
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;

            if (slowPointer == fastPointer) break;
        }

        if (fastPointer == nullptr || fastPointer->next == nullptr) 
            return nullptr;

        int loopLength = 0;
        do {
            slowPointer = slowPointer->next;
            loopLength++;
        } while (slowPointer != fastPointer);

        ListNode *listCrawler = head;
        ListNode *listCrawlerAhead = head;

        for (int k = 0; k < loopLength; k++)
            listCrawlerAhead = listCrawlerAhead->next;

        while (listCrawlerAhead != nullptr) {
            if (listCrawlerAhead == listCrawler)
                return listCrawler;
            else {
                listCrawler = listCrawler->next;
                listCrawlerAhead = listCrawlerAhead->next;
            }
        }

        return nullptr;
    }
};