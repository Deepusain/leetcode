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
    vector<int> helper(TreeNode* root, int &distance, int &count){
        if(root == NULL){
            vector<int> temp;
            return temp;
        }

        //if leaf node then return 1 in a vector
        if(root->left == NULL && root->right == NULL){
            vector<int> temp = {1};
            return temp;
        }

        //else visit left and right nodes
        vector<int> left = helper(root->left, distance, count);
        vector<int> right = helper(root->right, distance, count);
        vector<int> combined;

        
        for(auto it: left){
            combined.push_back(it+1);
        }
        for(auto it: right){
            combined.push_back(it+1);
        }
        for(int i=0; i<left.size(); i++){
            for(int j=0; j<right.size(); j++){
                //cout<<" inside"<<endl;
                int sum = left[i] + right[j];
                if(sum <= distance){
                    count++;
                }
            }
        }
        
        return combined;
        
    }

    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        vector<int> temp = helper(root, distance, count);

        return count;
    }
};