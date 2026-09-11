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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        // caz 2: ambii in in stanga
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        // caz 3: ambii in dreapta
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        // caz 1: sunt in subarbori diferiti
        return root;
    }
};
