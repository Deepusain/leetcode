const int A=1e3+1, MOD=1e9+7;

class Solution {
public:
    int countOfPairs(vector<int>& v) {
        static int dp[A], ndp[A];
        memset(dp, 0, sizeof dp);
        for (int i=0; i<=v[0]; i++) {
            dp[i]=1;
        }
        for (int i=1; i<v.size(); i++) {
            int x=v[i-1];
            int y=v[i];
            for (int j=1; j<A; j++) {
                dp[j] += dp[j-1];
                if (dp[j] >= MOD) dp[j] -= MOD;
            }
            for (int j=0; j<=y; j++) {
                int p=j;
                p = min(p, x+j-y);
                ndp[j] = 0;
                if (p>=0) ndp[j] = dp[p];
            }
            for (int j=y+1; j<A; j++) ndp[j]=0;
            swap(dp, ndp);
        }
        int s=0;
        for (int a=0; a<A; a++) {
            s += dp[a];
            if (s >= MOD) s -= MOD;
        }
        return s;
        
    }
};
// class Solution {
// public:
//     const int MOD = 1e9 + 7;

//     int countOfPairs(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(nums[0] + 1, 0));

//         // Base case: first element
//         for (int i = 0; i <= nums[0]; ++i) {
//             dp[0][i] = 1;
//         }

//         // Fill the DP table
//         for (int i = 1; i < n; ++i) {
//             vector<int> prefix_sum(nums[i] + 1, 0);
//             for (int j = 0; j <= nums[i]; ++j) {
//                 prefix_sum[j] = dp[i - 1][j] + (j > 0 ? prefix_sum[j - 1] : 0);
//                 prefix_sum[j] %= MOD;
//             }

//             for (int j = 0; j <= nums[i]; ++j) {
//                 dp[i][j] = prefix_sum[j];
//             }
//         }

//         // Sum up the last row of the DP table
//         int result = 0;
//         for (int i = 0; i <= nums[n - 1]; ++i) {
//             result = (result + dp[n - 1][i]) % MOD;
//         }

//         return result;
//     }
// };