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
    int curr_sum=0;
public:
    TreeNode* bstToGst(TreeNode* root) 
    {
        travelSum(root);
        return root;
    }
    
    void travelSum(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->right)
            travelSum(root->right);
        curr_sum+=root->val;
        root->val=curr_sum;
        if(root->left)
            travelSum(root->left);
    }
};