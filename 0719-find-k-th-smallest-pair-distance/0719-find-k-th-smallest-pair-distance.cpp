class Solution {
public:
    // Function to count the number of pairs with distance less than or equal to mid
    int countPairs(const vector<int>& nums, int mid) {
        int count = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > mid) {
                ++left;
            }
            count += right - left;
        }
        return count;
    }

    // Function to find the k-th smallest distance
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();

        while (low < high) {
            int mid = (low + high) / 2;
            if (countPairs(nums, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
//     int smallestDistancePair(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int low = 0, high = nums[n - 1] - nums[0];

//         auto count_pairs = [&](int max_distance) {
//             int count = 0, j = 0;
//             for (int i = 0; i < n; ++i) {
//                 while (j < n && nums[j] - nums[i] <= max_distance) ++j;
//                 count += j - i - 1;
//             }
//             return count;
//         };

//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if (count_pairs(mid) < k) low = mid + 1;
//             else high = mid;
//         }

//         return low;
//     }
};