// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {     
        vector<vector<int>> levelNodes;
        if(root == NULL)
            return levelNodes;
        
        queue<TreeNode*> q;
        q.push(root);
        int leftToRight = 1;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> nodes(size);     
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                
                int index = (leftToRight) ? i : size - 1 - i;
                nodes[index] = node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            levelNodes.push_back(nodes);
        }
        
        return levelNodes;
    }
};

/*
        bool f = true;
        deque<TreeNode*> q;
        q.push_front(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<int> nodes;     
            while(n--){
                if(f){
                    TreeNode* curr = q.front();
                    nodes.push_back(curr->val);
                    q.pop_front();                   
                    if(curr->left)  q.push_back(curr->left);
                    if(curr->right) q.push_back(curr->right);                    
                }
                else{
                    TreeNode* curr = q.back();
                    nodes.push_back(curr->val);
                    q.pop_back();
                    if(curr->right) q.push_front(curr->right);
                    if(curr->left)  q.push_front(curr->left);
                }
                
            }
            levelNodes.push_back(nodes);
            f = !f;
        }

*/