class Solution {
public:
    // using do explore undo approach
    
    // helper function
    void helper(vector<int>& candidates,int target,vector<int>& curr, int idx,vector<vector<int>>& result){
        if(target <0) return;
        if(target == 0){
            result.push_back(curr);
            return;
        }
        for(int i =idx;i<candidates.size();i++){
            curr.push_back(candidates[i]);//DO
            helper(candidates,target-candidates[i],curr,i,result);
            // helper(candidates,target-candidates[i],curr,i+1,result);
            curr.pop_back(); //Undo
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,curr,0,result);
        return result;
    }
};