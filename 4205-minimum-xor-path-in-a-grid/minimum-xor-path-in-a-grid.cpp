class Solution {
public:
    int m, n;
    // 3D DP टेबल: dp[row][col][current_xor]
    // m * n <= 1000 है, और मैक्सिमम XOR 1024 हो सकता है
    vector<vector<vector<int>>> dp;

    int dfs(int i, int j, int current_xor, vector<vector<int>>& grid) {
        // ग्रिड के करंट सेल का XOR मिक्स करें
        int new_xor = current_xor ^ grid[i][j];

        // बेस केस: अगर आखिरी सेल (Bottom-Right) पर पहुँच गए हैं
        if (i == m - 1 && j == n - 1) {
            return new_xor;
        }

        // चेक करो: क्या इस स्टेट (i, j, new_xor) का आंसर पहले से याद है?
        if (dp[i][j][new_xor] != -1) {
            return dp[i][j][new_xor];
        }

        int right = INT_MAX;
        int down = INT_MAX;

        // राइट जाने का रास्ता
        if (j < n - 1) {
            right = dfs(i, j + 1, new_xor, grid);
        }
        // नीचे जाने का रास्ता
        if (i < m - 1) {
            down = dfs(i + 1, j, new_xor, grid);
        }

        // दोनों रास्तों में से जो फाइनल XOR सबसे छोटा देगा, उसे स्टोर करें
        return dp[i][j][new_xor] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // 3D DP टेबल को -1 से इनिशियलाइज़ करें (Size: m x n x 1024)
        dp.assign(m, vector<vector<int>>(n, vector<int>(1024, -1)));

        // शुरुआत में (0,0) सेल पर जाएँ और स्टार्टिंग XOR 0 रखें
        return dfs(0, 0, 0, grid);
    }
};
