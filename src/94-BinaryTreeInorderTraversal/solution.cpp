/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    vector<int> v;
    vector<int> inorderTraversal_iter(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        while (root != NULL || !s.empty()) {
            if (root != NULL) {
                s.push(root);
                root = root->left;     
            } else {
                root = s.top();  // Stack elements are not NULL.
                s.pop();
                v.push_back(root->val);
                root = root->right;
            }
        }
        return v;
    }

    vector<int> v;
    vector<int> inorderTraversal_recursive(TreeNode* root) {
        
        if (root != NULL) {
            inorderTraversal(root->left);
            v.push_back(root->val);
            inorderTraversal(root->right);
        }
        
        return v;
    }
};