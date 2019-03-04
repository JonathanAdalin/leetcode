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
    
    // O(n) - We only go through each node once
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }  
        return traverse(root->left, root->right);
    }
    
    bool traverse(TreeNode* left, TreeNode* right) {
        if (left != NULL && right != NULL) {
            if (left->val == right->val) {
                return (traverse(left->left, right->right)
                        && traverse(left->right, right->left));
            } else {
                return false;
            }
        } else if (left == NULL && right == NULL) {
            return true;
        }  // Uneven children
        return false;
    }
    
};