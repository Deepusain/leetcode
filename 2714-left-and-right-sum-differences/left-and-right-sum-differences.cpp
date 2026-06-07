class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>res;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int curr=0;
        for(int i=0;i<nums.size();i++){
            int left_sum=curr;
            curr += nums[i];
            int right_sum=sum-curr;
            res.push_back(abs(right_sum-left_sum));
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> leftRightDifference(vector<int>& nums) {
//         vector<int>res;
//         int right_sum=0;
//         int left_sum=0;
//         for(int i=0;i<nums.size();i++){
//             right_sum+=nums[i];
//         }
        
//         for(int i=0;i<nums.size();i++){
//             right_sum-=nums[i];
//             res.push_back(abs(right_sum-left_sum));
//             left_sum+=nums[i];
//         }
//         return res;
//     }
// };