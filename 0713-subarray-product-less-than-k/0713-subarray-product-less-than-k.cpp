class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int ans = 0 ; 
        if(k<=1){
           return 0 ; 
        }
        long long pro = 1 ; 
        int j = 0 ; 
        for(int i =0 ; i<n ; i++){

            pro *= nums[i] ; // keep calculating the product from j to i ; 

            
            
            while(pro>=k){
              //keep shifting the window forward to bring the product less than k 
              pro/= nums[j] ; 
              j++ ; 

            }

            if(pro<k){
                // continue calculating the answer until prod>=k
                ans += i-j+1 ;
            }
        }

        return ans ; 

    }
};