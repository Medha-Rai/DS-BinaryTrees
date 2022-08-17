/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool getPath(TreeNode *root, vector<int> &res, int x) {
    if(root == NULL)
        return false;
        
    res.push_back(root->val);
    
    if(root->val == x)
        return true;
    
    if(getPath(root->left, res, x) || getPath(root->right, res, x))
        return true;
    
    res.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    if(A == NULL) return res;
    
    getPath(A, res, B);
    return res;
}
