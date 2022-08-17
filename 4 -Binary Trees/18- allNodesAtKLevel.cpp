// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

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
private:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);
        // parent[root] = NULL;
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            if(curr->left) {
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            if(curr->right) {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }   
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // 1. map parent ptrs
        // 2. move in 3 directions from target (up, left, right)
        // 3. have a vis map so while moving upward the same node is not done twice
        unordered_map<TreeNode*, TreeNode*> parent;
        
        markParents(root, parent);
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        
        q.push(target);
        vis[target] = true;

        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            if(k == dist) break;
            
            for(int i = 0; i < size; i++){
                auto curr = q.front(); q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                
                if(parent[curr] && !vis[parent[curr]]){
                    // cout<< parent[curr]->val <<" ";
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }
            dist++;
        }
        vector<int> nodes;
        while(!q.empty()){
            nodes.push_back(q.front()->val);
            q.pop();
        }
        return nodes;
    }
};