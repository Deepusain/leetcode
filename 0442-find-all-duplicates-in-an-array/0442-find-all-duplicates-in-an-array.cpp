class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        vector<int>ans;
        while(i<nums.size()-1){
            if(nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
                i+=2;
            }else{
                i++;
            }
        }
        return ans;
    }
};