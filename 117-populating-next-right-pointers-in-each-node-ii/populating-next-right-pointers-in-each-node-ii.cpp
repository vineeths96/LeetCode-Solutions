/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;

        Node *levelStart = root;
        while (levelStart != nullptr) {
            Node *head = levelStart;
            Node *previous = nullptr;
            levelStart = nullptr;
            while (head != nullptr) {
                if (head->left != nullptr) {
                    if (previous != nullptr)
                        previous->next = head->left;
                    else
                        levelStart = head->left;

                    previous = head->left;
                }

                if (head->right != nullptr) {
                    if (previous != nullptr)
                        previous->next = head->right;
                    else
                        levelStart = head->right;

                    previous = head->right;
                }

                head = head->next;
            }
        }

        return root;
    }
};