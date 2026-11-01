class Solution {
public:
    int min(vector<int>& nums){
        int ans=nums[0];
        for(auto& i:nums){
            if(i<ans) ans=i;
        }
        return ans;
    }
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mn=min(nums);
        int ans=0;
        for(auto& i:nums){
            ans+=i-mn;
        }
        return ans;
    }
};