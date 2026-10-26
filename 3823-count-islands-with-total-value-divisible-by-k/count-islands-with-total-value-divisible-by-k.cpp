class Solution {
public:
    int m,n;

    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};

    long long dfs(int i,int j ,vector<vector<int>>& grid){
        long long sum=grid[i][j];
        grid[i][j]=0;

        for(vector<int> dir : directions){
            int i_new = i+dir[0]; 
            int j_new = j+dir[1];

            if(i_new>=0 && i_new<m & j_new>=0 && j_new<n && grid[i_new][j_new]>0){
                sum +=dfs(i_new,j_new, grid);
            } 
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]>0){
                    long long sum = dfs(i,j,grid);
                    if(sum%k ==0) count++;
                }
            }
        }
        return count;
    }
};