//  https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = leftmostHeight(root);
        int rh = rightmostHeight(root);

        // complete binary tree at current node
        if(lh == rh) return (1<<lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int leftmostHeight(TreeNode *root) {
        int h = 0;
        while(root){
            h++;
            root = root->left;
        }
        return h;
    }
    int rightmostHeight(TreeNode *root) {
        int h = 0;
        while(root){
            h++;
            root = root->right;
        }
        return h;
    }
};