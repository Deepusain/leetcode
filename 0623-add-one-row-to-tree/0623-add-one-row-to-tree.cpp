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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
      if(root==NULL)return  root;
        if(depth==0)return root;
        if(depth==1){
            TreeNode* nr = new TreeNode(val);
            nr->left = root;
            nr->right = nullptr;
            return nr;
        }
        if(depth==2){
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = l;
            root->right->right = r;
            return root;
        }
        addOneRow(root->left,val,depth-1);
        addOneRow(root->right,val,depth-1);
        return root;
    }
};
// class Solution {
// public:
//     TreeNode* addOneRow(TreeNode* root, int v, int d){
//         if(d==1 && root!=NULL){
//             TreeNode* nr = new TreeNode(v, root, NULL);
//             return nr;
//         }
//         if(d==2 && root!=NULL){
//             TreeNode* nl = new TreeNode(v, root->left, NULL);
//             TreeNode* nr = new TreeNode(v, NULL, root->right);
//             root->left=nl;
//             root->right=nr;
//             return root;
//         }
//         if(root==NULL){
//             return NULL;
//         }
//         addOneRow(root->left, v, d-1);
//         addOneRow(root->right, v, d-1);
//         return root;
//     }
// };