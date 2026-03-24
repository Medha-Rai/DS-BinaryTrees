// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder;
        
        TreeNode* curr = root;
        stack<TreeNode*> s;
        s.push(curr);
        while(!s.empty()){
            preorder.push_back(s.top()->val);
            curr = s.top(); s.pop();
            
            if(curr->right) s.push(curr->right);
            if(curr->left)  s.push(curr->left);
        }
        return preorder;
    }
};