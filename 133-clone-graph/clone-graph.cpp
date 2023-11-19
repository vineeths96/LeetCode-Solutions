/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    std::unordered_map<Node*, Node*> nodeMap;

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        if (nodeMap.find(node) != nodeMap.end())
            return nodeMap[node];

        Node *cloneNode = new Node(node->val);
        nodeMap[node] = cloneNode;
        for (Node *neighbor : node->neighbors)
            cloneNode->neighbors.push_back(cloneGraph(neighbor));

        return cloneNode;
    }
};