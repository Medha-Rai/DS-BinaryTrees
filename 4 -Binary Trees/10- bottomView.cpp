// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> bottomview;
        if(root == NULL) return bottomview;
        
        map<int,int> mp;
        // q({node, line})
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            Node* node = curr.first;
            int line = curr.second;
            
            //  line=0
            //   |  level 1
            //   |  level 2 <-
            // so need last node of this line
            // ie last level of each verticals;
            mp[line] = node->data;
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        
        for(auto p : mp){
            bottomview.push_back(p.second);
        }
        return bottomview;
    }
};