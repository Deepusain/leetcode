class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // 1. Grid initialize kari (# se)
        vector<vector<char>> board(m, vector<char>(n, '#'));
        vector<string> res;
        
        int i = 0;
        int j = 0;
        board[i][j] = '.'; // Starting point
        
        // 2. Loop tab tak chalega jab tak dono corners tak na pahunch jayein (OR condition)
        while (i < m - 1 || j < n - 1) {
            if (j < n - 1) { // Pehle right jao agar jagah hai
                j++;
                board[i][j] = '.';
            }
            if (i < m - 1) { // Fir down jao agar jagah hai
                i++;
                board[i][j] = '.';
            }
        }
        
        // 3. Sahi variables (a aur b) ka use karke result vector banana
        for (int a = 0; a < m; a++) {
            string add = "";
            for (int b = 0; b < n; b++) {
                add += board[a][b]; // Fix: i, j ki jagah a, b use kiya
            }
            res.push_back(add);
        }
        
        return res;
    }
};
