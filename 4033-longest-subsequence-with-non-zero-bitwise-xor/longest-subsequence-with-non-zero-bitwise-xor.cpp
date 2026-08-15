class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size(),total_Xor=0;
        bool allZeroElement=true;
        for(int &num:nums){
            total_Xor ^=num;
            if(num !=0){
                allZeroElement=false;
            }
        }
        if(allZeroElement){
            return 0;
        }
        if(total_Xor !=0){
            return n;
        }
        return n-1;
    }
};
