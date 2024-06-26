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
    void inorder(TreeNode* root, vector<int> &in){
        // base case
        if(!root) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    
    TreeNode* createBST(vector<int> &in, int st, int end){
        // base case
        if(st > end) return NULL;
        
        int mid = (st+end)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = createBST(in, st, mid-1);
        root->right = createBST(in, mid+1, end);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        return createBST(in, 0, in.size()-1);
    }
};