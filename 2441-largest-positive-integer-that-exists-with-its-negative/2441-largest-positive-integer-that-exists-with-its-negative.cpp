class Solution {
public:
    static int findMaxK(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int lo = 0;
        int hi = size(nums) - 1;
        while (lo < hi) {
            if (-nums[lo] == nums[hi]) {
                return nums[hi];
            } else if (-nums[lo] > nums[hi]) {
                ++lo;
            } else {
                --hi;
            }
        }
        return -1;
    }
};