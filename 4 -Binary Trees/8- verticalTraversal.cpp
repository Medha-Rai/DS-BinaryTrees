// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    void dfs(TreeNode* root, int vertical, int level, map<int, map<int, multiset<int>>> &mp){
        if(root == NULL)
            return;
        
        mp[vertical][level].insert(root->val);
        dfs(root->left, vertical - 1, level + 1, mp);
        dfs(root->right, vertical + 1, level + 1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        dfs(root, 0, 0, mp);
        vector<vector<int>> nodes;
        
        for(auto p : mp){
            vector<int> col;
            for(auto q : p.second)
                col.insert(col.end(),q.second.begin(), q.second.end());
            nodes.push_back(col);
        }
        return nodes;       
    }
};