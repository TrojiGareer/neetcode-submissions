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
    void reorderList(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while (second != nullptr && second->next != NULL) {
            first = first->next;
            second = second->next->next;
        }
        ListNode* curr = first->next;
        first->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        while (curr != nullptr) {
            temp = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = temp;
        }
        ListNode* l1 = head;
        ListNode* l2 = prev;
        ListNode* tmp2 = nullptr;
        while (l2 != nullptr) {
            temp = l1->next;
            tmp2 = l2->next;
            l1->next = l2;
            l2->next = temp;
            l1 = temp;
            l2 = tmp2;
        }
    }
};
