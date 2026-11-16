// class Solution {
// public:
//     int check(vector<int>& nums,int k){
//         int res=0;
//         for(int i=0;i<k;i++){
//             res+=nums[i];
//         }
//         int a=res;
//         if(res<0)res=0;
//         for(int i=k;i<nums.size();i++){
//             a+=nums[i]-nums[i-k];
//             if(a>0){
//                 if(res>0){
//                     res=min(a,res);
//                 }else{
//                     res=a;
//                 }
//             }
//         }
//         if(res ==0)return -1;
//         return res;
//     }
//     int minimumSumSubarray(vector<int>& nums, int l, int r) {
//         int a=check(nums,l);
//         int b=check(nums,r);
//         if(a==b==-1){
//             return -1;
//         }else if(a==-1 && b>0){
//             return b;
//         }else if(a>0 && b==-1){
//             return a;
//         }
//         return min(a,b);
//     }
// };


class Solution {
public:
    // Yeh function exact 'k' size ke subarrays mein minimum positive sum nikalega
    int check(vector<int>& nums, int k) {
        int res = INT_MAX;
        int currentSum = 0;
        
        // Pehli window (size k) ka sum
        for (int i = 0; i < k; i++) {
            currentSum += nums[i];
        }
        if (currentSum > 0) {
            res = min(res, currentSum);
        }
        
        // Baaki windows ko slide karke check karenge
        for (int i = k; i < nums.size(); i++) {
            currentSum += nums[i] - nums[i - k];
            if (currentSum > 0) {
                res = min(res, currentSum);
            }
        }
        
        return (res == INT_MAX) ? -1 : res;
    }

    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        
        // l se lekar r tak har possible size 'k' ke liye check karenge
        for (int k = l; k <= r; k++) {
            int temp = check(nums, k);
            if (temp != -1) {
                ans = min(ans, temp);
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};
