class Solution {
public:
    void solve(int i,int j ,vector<vector<int>>& grid ){
        if(grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        if(i>0){
            solve(i-1,j,grid);
        }
        if(j>0){
            solve(i,j-1,grid);
        }
        if(grid[0].size()-1>j){
            solve(i,j+1,grid);
        }
        if(grid.size()-1>i){
            solve(i+1,j,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1){
                solve(i,0,grid);
            }
        }
        for(int i=0;i<grid.size();i++){
            if(grid[i][grid[0].size()-1]==1){
                solve(i,grid[0].size()-1,grid);
            }
        }
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1){
                solve(0,i,grid);
            }
        }
        for(int i=0;i<grid[0].size();i++){
            if(grid[grid.size()-1][i]==1){
                solve(grid.size()-1,i,grid);
            }
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};