// https://practice.geeksforgeeks.org/problems/children-sum-parent/1

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     if(root == NULL) return 1;
     
     int tot = 0;
     if(root->left) tot += root->left->data;
     if(root->right) tot += root->right->data;
     
     // if a node is non leaf
     // then only can check for children sum
     if(root->left || root->right){
        if(tot != root->data)
        return 0;
     }
       
        
     if((root->left && isSumProperty(root->left) == 0)
        || (root->right && isSumProperty(root->right) == 0))
        return 0;
    
     return 1;
    }
};