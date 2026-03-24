// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        // q{node, node number}
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int width = 0;
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;   // to make id starting from 0
            int first, last;        
            for(int i = 0; i < size; i++){
                TreeNode *curr = q.front().first;
                int num = q.front().second-mmin;
                q.pop();
                
                if(i==0) first = num;
                if(i==size-1) last = num;
                
                if(curr->left) q.push({curr->left, 1LL*num*2+1});
                if(curr->right) q.push({curr->right, 1LL*num*2+2});
            }
            width = max(width, last-first+1);
        }
        return width;
    }
};