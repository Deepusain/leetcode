class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int f[51]={0};
        for(auto& i:nums)f[i]++;
        int res=-1;
        int n=nums.size();
        if(k==n){
            for(int i=50;i>=0;i--){
                if (f[i]!=0){
                    return i;
                }
            }
        }else if (k==1){
            for(int i=50;i>=0;i--){
                if (f[i]==1){
                    return i;
                }
            }
        }else {
            if (f[nums[0]] ==1) res = max(res,nums[0]);
            if (f[nums[n-1]] ==1) res = max(res,nums[n-1]);
        }
        return res;
    }
};