// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

    int pathSumUtil(TreeNode *root, int &maxSum){
        if(root == NULL)
            return 0;
        
        // nodes caan be -ve so taking only +ve sum
        // and moving forward
        int lsum = max(0, pathSumUtil(root->left, maxSum));
        int rsum = max(0, pathSumUtil(root->right, maxSum));     

        maxSum = max(maxSum, root->val + lsum + rsum);
        
        return root->val + max(lsum, rsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        pathSumUtil(root, maxSum);
        return maxSum; 
    }
};