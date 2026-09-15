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
#include <string>
#include <cstring>
// #include <string.h>

class Codec {
private:
    string res;
    void helper(TreeNode* node) {
        if (node == nullptr) {
            res.append("N,");
            return;
        }
        res.append(to_string(node->val));
        res.append(",");
        helper(node->left);
        helper(node->right);
    }

    TreeNode* decode(queue<string>& tree) {
        if (tree.empty()) return nullptr;
        string s = tree.front();
        tree.pop();
        if (s == "N") return nullptr;
        int val = stoi(s);
        TreeNode* root = new TreeNode(val);
        root->left = decode(tree);
        root->right = decode(tree);
        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        res = "";
        helper(root);
        res[res.length() - 1] = '\0';
        cout<<res<<endl;

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        char* p = strtok(data.data(), ",");
        queue<string> tree;
        while (p != nullptr) {
            tree.push(p);
            p = strtok(NULL, ",");
        }
        return decode(tree);
    }
};
