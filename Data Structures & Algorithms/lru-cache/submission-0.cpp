#include <unordered_map>

using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int capacitate;
    unordered_map<int, Node*> cache;
    Node* left;  // (MRU)
    Node* right; // (LRU)

    void stergeNod(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insereazaLaStanga(Node* node) {
        Node* first = left->next;
        node->next = first;
        first->prev = node;
        left->next = node;
        node->prev = left;
    }

public:
    LRUCache(int capacity) {
        capacitate = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            stergeNod(cache[key]);
            insereazaLaStanga(cache[key]);
            return cache[key]->val;
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            stergeNod(cache[key]);
        }
        Node* newNode = new Node(key, value);
        insereazaLaStanga(newNode);
        cache[key] = newNode;
        if (cache.size() > capacitate) {
            cache.erase(right->prev->key);
            stergeNod(right->prev);
        }
    }
};