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
    unordered_map<int, int> inorderIndexMap;
    int preorderIndex = 0;
    
    TreeNode* helper(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        int rootVal = preorder[preorderIndex];
        preorderIndex++;
        
        TreeNode* root = new TreeNode(rootVal);
        int midIndex = inorderIndexMap[rootVal];
        root->left = helper(preorder, inStart, midIndex - 1);
        root->right = helper(preorder, midIndex + 1, inEnd);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return helper(preorder, 0, inorder.size() - 1);
    }
};
