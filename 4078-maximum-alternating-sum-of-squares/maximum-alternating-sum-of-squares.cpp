class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            long long k=nums[i];
            nums[i]=k*k;
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            if(i==j){
                ans+= nums[i];
            }else{
                long long k=nums[j]-nums[i];
                ans+=k;
            }
            i++;
            j--;
        }
        return ans;
    }
};