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
    string result; // our final answer , smallest string from Leaf
    
    void solve(TreeNode* root , string running) { // O(N) comparisons
        
        if(root->left == nullptr && root->right == nullptr){
            running +=(root->val +'a');
            
            reverse(running.begin(),running.end());
            
            if(running.length()>0 && result> running){
                result = running;
            }
            
            reverse(running.begin() ,running.end());
            return;
        }
        
        running += (root->val +'a');
        
        if(root->left) solve(root->left , running);
        if(root->right) solve(root->right , running);
    }
    
    string smallestFromLeaf(TreeNode* root) { // O(N) comparisons
        result = string(1,'z'+1); // char '{' =>ascii value 123
        
        solve(root,"");
        
        return result;
    }
};