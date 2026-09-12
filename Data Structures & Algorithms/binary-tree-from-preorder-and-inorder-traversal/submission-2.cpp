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
private:
    int inorderMap[2001];
    int preorderIndex = 0;
    
    TreeNode* helper(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal + 1000];
        root->left = helper(preorder, inStart, mid - 1);
        root->right = helper(preorder, mid + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i] + 1000] = i;
        }
        
        return helper(preorder, 0, inorder.size() - 1);
    }
};
