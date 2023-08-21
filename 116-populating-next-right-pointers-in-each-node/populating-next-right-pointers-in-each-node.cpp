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

        std::queue<Node*> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty()) {
            int numNodesInLevel = bfsQueue.size();
            Node *previous = nullptr;
            Node *current = nullptr;
            for (int i = 0; i < numNodesInLevel; i++) {
                current = bfsQueue.front();
                bfsQueue.pop();

                if (previous != nullptr)
                    previous->next = current;
                
                previous = current;

                if (current->left != nullptr) bfsQueue.push(current->left);
                if (current->right != nullptr) bfsQueue.push(current->right);                
            }

            current->next = nullptr;
        }

        return root;
    }
};