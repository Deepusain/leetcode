class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n = nums.size();
        int ans = 0;
        int i=0,j=0;
        while(j < n){
            freq[nums[j]]++;
            while(freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};