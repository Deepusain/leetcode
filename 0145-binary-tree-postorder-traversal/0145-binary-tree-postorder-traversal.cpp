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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int>postorder;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr = s.top();
            if(curr->left){
                s.push(curr->left);
                curr->left = NULL;
            }
            else{
                if(curr->right){
                    s.push(curr->right);
                    curr->right = NULL;
                }
                else{
                    postorder.push_back(curr->val);
                    s.pop();
                }
            }
        }
        return postorder;
    }
//     // Recursive Approx
//     // Recursive function for postorder traversal
//     void postorder(TreeNode* root, vector<int>& result) {
//         if (root == nullptr) {
//             return;
//         }
//         // Traverse the left subtree
//         postorder(root->left, result);
//         // Traverse the right subtree
//         postorder(root->right, result);
//         // Process the root node
//         result.push_back(root->val);
//     }
    
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         postorder(root, result);
//         return result;
//     }
};