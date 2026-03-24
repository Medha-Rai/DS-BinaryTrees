#include <bits/stdc++.h>
using namespace std;

// BFS code
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> mp;
        vector<int> topnodes;
        if(root == NULL) return topnodes;
        
        // q({node, vertical})
        queue<pair<Node*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            Node *node = curr.first;
            int vertical = curr.second;
            if(mp.find(vertical) == mp.end()) mp[vertical] = node->data;
            
            if(node->left) q.push({node->left, vertical-1});
            if(node->right) q.push({node->right, vertical+1});
        }
        
        for(auto p : mp){
            topnodes.push_back(p.second);
        }
        return topnodes;
    }

};


// DFS code
/*
        void Topview(Tree * head, int dis, int level, auto & mp) {
          if (head == nullptr) {
            return;
          }
          if (mp.find(dis) == mp.end() || level < mp[dis].second) {
            mp[dis] = {
              head -> key,
              level
            };
          }
          Topview(head -> left, dis - 1, level + 1, mp);
          Topview(head -> right, dis + 1, level + 1, mp);
        }
        void Topview(Tree * head) {
          mp < int, pair < int, int >> mp;
          Topview(head, 0, 0, mp);
          for (auto it: mp) {
            cout << it.second.first << " ";
          }
        }
*/


int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends