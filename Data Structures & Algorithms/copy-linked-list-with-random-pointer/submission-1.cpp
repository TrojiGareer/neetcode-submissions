/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         if (head == nullptr) return nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* copie = new Node(curr->val);
            copie->next = curr->next;
            curr->next = copie;
            curr = copie->next;
        }
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* copieHead = head->next;
        Node* copieCurr = copieHead;
        while (copieCurr != nullptr) {
            if (copieCurr->next != nullptr) {
                copieCurr->next = copieCurr->next->next;
            }
            copieCurr = copieCurr->next;
        }
        
        return copieHead;
    }
};
