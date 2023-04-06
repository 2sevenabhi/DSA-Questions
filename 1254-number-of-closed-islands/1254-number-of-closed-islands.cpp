class Solution {
public:
void dfs(vector<vector<int>>&grid, int row, int column, vector<int>&dr, vector<int>&dc)
{
    grid[row][column]=1;
    int n=grid.size();
    int m=grid[0].size();
    int i, nr, nc;
    for(i=0;i<4;i++)
    {
        nr=row+dr[i];
        nc=column+dc[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0)
        {
            dfs(grid, nr, nc, dr, dc);
        }
    }
}

    int closedIsland(vector<vector<int>>& grid) {
        int i,j;
        int noof=0;
        vector<int>dr{-1,0,1,0};
        vector<int>dc{0,1,0,-1};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if((i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1 ) && grid[i][j]==0)
                {
                    dfs(grid, i,j, dr,dc);
                }
            }
        }
         for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0)
                {
                    noof++;
                    dfs(grid, i,j,dr,dc);
                }
            }
        }
        return noof;

        
    }
};