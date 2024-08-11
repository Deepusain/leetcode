//More Optimized
class Solution {
public:
    // A helper function to perform Depth-First Search (DFS) to explore the island
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        // Check boundaries and whether the cell is already visited or is water
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || visited[i][j])
            return;
        visited[i][j] = true; // Mark the cell as visited
        // Recursively visit all 4 directions
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
    }

    // Function to count the number of islands (connected groups of 1's)
    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        // Iterate through the grid to find and count each island
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find a land cell that is not visited, start a new DFS
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(grid, visited, i, j); // Explore the island
                }
            }
        }
        return count;
    }
    
    // Function to determine the minimum number of days to disconnect the island
    int minDays(vector<vector<int>>& grid) {
        // Step 1: Check if the grid is already disconnected
        if (countIslands(grid) != 1) return 0;
        
        int m = grid.size(), n = grid[0].size();

        // Step 2: Try removing one land cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // Remove the land cell
                    // Check if removing this cell disconnects the grid
                    if (countIslands(grid) != 1) return 1;
                    grid[i][j] = 1; // Restore the land cell
                }
            }
        }

        // Step 3: If removing one cell isn't enough, return 2 (as it is guaranteed to be sufficient)
        return 2;
    }
};