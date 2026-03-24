// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr != NULL || !s.empty()){
            // cout <<"ii";
            if(curr != NULL){
                cout << curr->val;
                s.push(curr);
                curr = curr->left;
                
            }
            else {
                TreeNode* tmp = s.top()->right;
                if(tmp == NULL){
                    tmp = s.top();
                    s.pop();
                    postorder.push_back(tmp->val);
                    while(!s.empty() && tmp == s.top()->right){
                        tmp = s.top()->right; s.pop();
                        postorder.push_back(tmp->val);
                    }
                }
                else
                    curr = tmp;
            }
            
        }
        return postorder;
    }
};