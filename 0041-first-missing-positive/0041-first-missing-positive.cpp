class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int ans=1;
        while(i<nums.size()){
            if(ans<nums[i]){
                break;
            }else if(ans>nums[i]){
                i++;
            }else if(ans==nums[i]){
                ans++;
                i++;
            }
        }
        return ans;
    }
};