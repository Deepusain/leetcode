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
// class Solution {
// public:
//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//         if(depth == 1){
//             TreeNode* newRow =1
//         }
//     }
// };
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d){
        if(d==1 && root!=NULL){
            TreeNode* nr = new TreeNode(v, root, NULL);
            return nr;
        }
        if(d==2 && root!=NULL){
            TreeNode* nl = new TreeNode(v, root->left, NULL);
            TreeNode* nr = new TreeNode(v, NULL, root->right);
            root->left=nl;
            root->right=nr;
            return root;
        }
        if(root==NULL){
            return NULL;
        }
        addOneRow(root->left, v, d-1);
        addOneRow(root->right, v, d-1);
        return root;
    }
};