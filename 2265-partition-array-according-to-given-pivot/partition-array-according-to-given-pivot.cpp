class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> res(n);
        int left=0 , right=n-1;
        for(int i=0,j=n-1;i<n;i++,j--){
            if(nums[i]<pivot){
                res[left]=nums[i];
                left++;
            }
            if(nums[j]>pivot){
                res[right]=nums[j];
                right--;
            }
        }
        while(left<=right){
            res[left]=pivot;
            left++;
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         vector<int>ans ;
//         for(auto x : nums){
//             if(x < pivot)
//             ans.push_back(x);
//         }
//         for(auto x : nums){
//             if(x == pivot)
//             ans.push_back(x);
//         }
//         for(auto x : nums){
//             if(x >pivot)
//             ans.push_back(x);
//         }
//         return ans;
//     }
// };