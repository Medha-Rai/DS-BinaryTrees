// https://leetcode.com/problems/binary-tree-right-side-view/

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
    void dfs(TreeNode* node, vector<int> &res, int level) {
        if(node == NULL)
            return;
        
        if(res.size() == level)
            res.push_back(node->val);
        
        dfs(node->right, res, level + 1);
        dfs(node->left, res, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> rightnodes;
        if(root == NULL) return rightnodes;
        
        dfs(root, rightnodes, 0);
        return rightnodes;
    }
};

/*
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 1; i <= size; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                // last node of each level
                if(i == size)
                    nodes.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
*/