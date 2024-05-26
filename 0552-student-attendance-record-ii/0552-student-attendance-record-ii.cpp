class Solution {
public:
    int dp[(int)(1e5 + 1)][2][3], mod = 1e9 + 7;
    int solve(int idx, bool aTaken, int cnt, int n)
    {
        if (idx == n)
            return 1;

        if (dp[idx][aTaken][cnt] != -1)
            return dp[idx][aTaken][cnt];

        if (!aTaken)
        {
            int takeA = solve(idx + 1, true, 0, n);

            int takeL = 0;
            if (cnt != 2)
                takeL = solve(idx + 1, false, cnt + 1, n);

            int takeP = solve(idx + 1, false, 0, n);

            return dp[idx][aTaken][cnt] = ((takeA + takeL) % mod + takeP) % mod;
        }

        int takeL = 0;
        if (cnt != 2)
            takeL = solve(idx + 1, true, cnt + 1, n);

        int takeP = solve(idx + 1, true, 0, n);

        return dp[idx][aTaken][cnt] = (takeL + takeP) % mod;
    }
    int checkRecord(int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, false, 0, n);
    }
};