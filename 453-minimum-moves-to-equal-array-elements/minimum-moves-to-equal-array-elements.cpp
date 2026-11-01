class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mn=nums[0];
        int ans=0;
        for(auto& i:nums){
            ans+=i-mn;
        }
        return ans;
    }
};