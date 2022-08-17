// https://leetcode.com/problems/balanced-binary-tree/

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
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        
        // why checks when doing on both left & right?
        // because we need to check whether balance not only on root
        // but also on left & right child
        // so if either of the child are not balanced
        // then tree won't be balanced
        // so need to pass this to the calling func's
        int lh = height(root->left);
        // if(lh == -1) return -1; 
        int rh = height(root->right);
        // if(rh == -1) return -1;
        
        if(lh == -1 || rh == -1 || abs(lh-rh) > 1)
            return -1;
        
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return (height(root) != -1);
        
    }
};