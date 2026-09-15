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
    int maxSum = INT_MIN;
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = dfs(node->left);
        if (left < 0) left = 0;
        int right = dfs(node->right);
        if (right < 0) right = 0;
        int sum = node->val + left + right;
        maxSum = max(maxSum, sum);
        return node->val + max(left, right);

    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
