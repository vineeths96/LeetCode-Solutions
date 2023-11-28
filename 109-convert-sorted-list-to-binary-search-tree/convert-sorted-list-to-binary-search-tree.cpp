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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    ListNode *findMiddle(ListNode* start, ListNode *end) {
        ListNode *slowCrawler = start;
        ListNode *fastCrawler = start->next;

        while (fastCrawler != end) {
            slowCrawler = slowCrawler->next;

            if (fastCrawler->next == end) break;
            fastCrawler = fastCrawler->next->next;
        }

        return slowCrawler;
    }

    TreeNode *sortedListToBSTRecursive(ListNode *start, ListNode*end) {
        if (start == end)
            return nullptr;

        ListNode *middle = findMiddle(start, end);
        TreeNode *root = new TreeNode(middle->val);

        root->left = sortedListToBSTRecursive(start, middle);
        root->right = sortedListToBSTRecursive(middle->next, end);
        
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBSTRecursive(head, nullptr);
    }
};