class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min_val) {
                min_val = nums[i];
            }
            if (nums[i] > max_val) {
                max_val = nums[i];
            }
        }
        long long single_max_value = max_val - min_val;
        return single_max_value * k;
        // 1LL ka mtlb h ki long long ki data type h jiski multiply krne se chhota type (int) apne aap bade type (long long)
        return 1LL*(max_val - min_val)* k;

    }
};


// class Solution {
// public:
//     long long maxTotalValue(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         // 1. Pehle element se min aur max ko initialize karein
//         int min_val = nums[0];
//         int max_val = nums[0];
        
//         // 2. Single loop: Index 1 se end tak sirf ek baar scan karein
//         for (int i = 1; i < n; i++) {
//             if (nums[i] < min_val) {
//                 min_val = nums[i];
//             }
//             if (nums[i] > max_val) {
//                 max_val = nums[i];
//             }
//         }
        
//         // 3. Best single subarray ki value nikaalo
//         long long single_max_value = max_val - min_val;
        
//         // 4. Answer return karein
//         return single_max_value * k;

//     }
// };
