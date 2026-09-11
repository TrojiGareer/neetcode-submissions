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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        bool leftTree = isSameTree(p->left, q->left);
        bool rightTree = isSameTree(p->right, q->right);
        return leftTree && rightTree;
    }
    bool subtree = false;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        if (isSameTree(root, subRoot)) subtree = true;
        isSubtree(root->left, subRoot);
        isSubtree(root->right, subRoot);
        return subtree;
    }
};
