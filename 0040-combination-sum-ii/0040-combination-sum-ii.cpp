class Solution {
public:
    // using do explore undo approach
    
    // helper function
    void helper(vector<int>& candidates, int target,vector<int>& curr, int idx,vector<vector<int>>& result){
        if (target <0) return;
        if(target == 0) {result.push_back(curr);return;}
        
        for(int i=idx ; i<candidates.size();i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            
            curr.push_back(candidates[i]);//DO
            helper(candidates,target-candidates[i],curr,i+1,result);
            curr.pop_back(); //Undo
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        helper(candidates,target,curr,0,result);
        return result;
    }
};