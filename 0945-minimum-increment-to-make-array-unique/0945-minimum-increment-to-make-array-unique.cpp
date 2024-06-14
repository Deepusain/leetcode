class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans= 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] <= nums[i-1])
            {
                ans+=(nums[i-1]+ 1- nums[i]);
                nums[i]=nums[i-1]+1;
            }
        }
        return ans;
    }
};
/*

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        //sort the array
        sort(nums.begin(),nums.end());
        
        //since we cannot decrement a number
        //we need to increment the number to make adjacent values different
        int res=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                //increment the number to nums[i-1]
                res+=(nums[i-1]+ 1- nums[i]);
                nums[i]=nums[i-1]+1;
            }
        }
        return res;
    }
};
*/