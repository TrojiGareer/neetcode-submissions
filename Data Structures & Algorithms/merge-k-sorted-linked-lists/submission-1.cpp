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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while(!minHeap.empty()) {
            ListNode* elem = minHeap.top();
            minHeap.pop();
            curr->next = elem;
            curr = curr->next;
            if (elem->next != nullptr) {
                minHeap.push(elem->next);
            }
        }
        return head->next;
    }
};
