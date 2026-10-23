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
public:
    unordered_map<Node*, Node*> hashmap;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        if (hashmap[node] != nullptr) {
            return hashmap[node];
        }

        // if (hashmap[node] == nullptr) {
            hashmap[node] = new Node(node->val);
        // }

        for (Node* neigh : node->neighbors) {
            hashmap[node]->neighbors.push_back(cloneGraph(neigh));
        }

        return hashmap[node];
    }
};
