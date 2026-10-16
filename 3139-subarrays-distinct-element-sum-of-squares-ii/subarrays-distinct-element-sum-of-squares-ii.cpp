#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;
    // Segment Tree nodes structure
    vector<long long> tree_sum;
    vector<long long> tree_sqsum;
    vector<long long> lazy;

    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        
        int mid = start + (end - start) / 2;
        int left = 2 * node, right = 2 * node + 1;
        long long val = lazy[node];

        // Left child update
        long long left_len = mid - start + 1;
        tree_sqsum[left] = (tree_sqsum[left] + 2 * val * tree_sum[left] + val * val % MOD * left_len) % MOD;
        tree_sum[left] = (tree_sum[left] + val * left_len) % MOD;
        lazy[left] = (lazy[left] + val) % MOD;

        // Right child update
        long long right_len = end - mid;
        tree_sqsum[right] = (tree_sqsum[right] + 2 * val * tree_sum[right] + val * val % MOD * right_len) % MOD;
        tree_sum[right] = (tree_sum[right] + val * right_len) % MOD;
        lazy[right] = (lazy[right] + val) % MOD;

        lazy[node] = 0;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            long long len = end - start + 1;
            tree_sqsum[node] = (tree_sqsum[node] + 2 * val * tree_sum[node] + val * val % MOD * len) % MOD;
            tree_sum[node] = (tree_sum[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }

        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD;
        tree_sqsum[node] = (tree_sqsum[2 * node] + tree_sqsum[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        
        // Tree arrays ko resize karenge (4 * n size safe hota hai)
        tree_sum.assign(4 * n, 0);
        tree_sqsum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_pos;
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            // Agar element pehle nahi aaya toh last position -1 maanenge
            int last_idx = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            
            // last_idx + 1 se lekar j tak ke range me distinct count +1 hoga
            update(1, 0, n - 1, last_idx + 1, j, 1);
            
            // Total answer me pure tree ka square sum add kar denge
            ans = (ans + tree_sqsum[1]) % MOD;
            
            // Current element ki position save karenge
            last_pos[nums[j]] = j;
        }

        return ans;
    }
};
