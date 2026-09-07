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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1 != nullptr) {
            curr->next = l1;
        }
        if (l2 != nullptr) {
            curr->next = l2;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l2 = nullptr;
                if (i < (lists.size() - 1)) {
                    l2 = lists[i+1];
                }
                mergedLists.push_back(merge(lists[i], l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};
