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
    ListNode* reverse(ListNode* head, ListNode* nextGroup) {
        ListNode* curr = head;
        ListNode* tmp = nextGroup;
        ListNode* copy;
        do {
            copy = curr->next;
            curr->next = tmp;
            tmp = curr;
            curr = copy;
        } while (curr != nextGroup);
        return tmp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = new ListNode(0, head);
        ListNode* oldHead = head;
        ListNode *prevGroup, *nextGroup;
        prevGroup = res;
        while (prevGroup != nullptr) {
            ListNode* kth = prevGroup;
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }
            if (kth == nullptr) break;
            nextGroup = kth->next;
            oldHead = prevGroup->next;
            ListNode* newHead = reverse(oldHead, nextGroup);
            prevGroup->next = newHead;
            prevGroup = oldHead;
        }
        return res->next;
    }
};
