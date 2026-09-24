class Solution {
public:
    int digitsum (int& k){
        int sum=0;
        while(k>0){
            sum+= k%10;
            k/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if (i==digitsum(nums[i])){
                return i;
            }
        }
        return -1;
    }
};