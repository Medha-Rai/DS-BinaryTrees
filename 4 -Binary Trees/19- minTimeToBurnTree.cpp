// https://practice.geeksforgeeks.org/problems/burning-tree/1

class Solution {
  private:
    Node* bfsToMapParents(Node* root, map<Node*, Node*> &mpp, int target) {
        queue<Node*> q; 
        q.push(root); 
        Node* res; 
        while(!q.empty()) {
            auto node = q.front(); 
            // if target not given
            if(node->data == target) res = node; 
            
            q.pop(); 
            if(node->left) {
                mpp[node->left] = node; 
                q.push(node->left); 
            }
            if(node->right) {
                mpp[node->right] = node;
                q.push(node->right); 
            }
        }
        return res; 
    }
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> mpp; 
        Node *t = bfsToMapParents(root, mpp, target); 
    
        queue<Node*> q; 
        q.push(t); 
        map<Node*,int> vis; 
        vis[t] = 1;
        int time = 0; 
        while(!q.empty()) {
            int sz = q.size();
            int fl = 0; 
            for(int i = 0; i<sz; i++) {
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]) {
                    fl = 1; 
                    vis[node->left] = 1; 
                    q.push(node->left); 
                }
                if(node->right && !vis[node->right]) {
                    fl = 1; 
                    vis[node->right] = 1; 
                    q.push(node->right); 
                }
                
                if(mpp[node] && !vis[mpp[node]]) {
                    fl = 1; 
                    vis[mpp[node]] = 1; 
                    q.push(mpp[node]); 
                } 
            }
            if(fl) time++; 
        }
        return time; 
    }
};