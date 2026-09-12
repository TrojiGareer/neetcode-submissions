/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void inOrder(TreeNode* node, int &count, int k, int &res) {
        if (node == nullptr) return;
        inOrder(node->left, count, k, res);
        count += 1;
        if (count == k) {
            res = node->val;
            return;
        }
        inOrder(node->right, count, k, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, res;
        inOrder(root, cnt, k, res);
        return res;
    }
};
