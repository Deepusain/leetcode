class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        // 1. Pehle element se min aur max ko initialize karein
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        
        // 2. Single loop: Index 1 se end tak sirf ek baar scan karein
        for (int i = 0; i < n; i++) {
            if (nums[i] < min_val) {
                min_val = nums[i];
            }
            if (nums[i] > max_val) {
                max_val = nums[i];
            }
        }
        
        // 3. Best single subarray ki value nikaalo
        long long single_max_value = max_val - min_val;
        
        // 4. Answer return karein
        return single_max_value * k;

    }
};