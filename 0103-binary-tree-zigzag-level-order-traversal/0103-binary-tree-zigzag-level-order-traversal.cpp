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
    void helper(TreeNode*root,vector<vector<int>>&ans,int level)
    {
        if(!root) return;   
        if(level>=ans.size())
            ans.push_back({});
        ans[level].push_back(root->val);
        helper(root->left,ans,level+1);
        helper(root->right,ans,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)   return ans;
        helper(root,ans,0); 
        for(int i=1;i<ans.size();i=i+2)
        {
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};