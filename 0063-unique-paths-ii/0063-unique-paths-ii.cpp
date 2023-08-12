class Solution {
public:
    int dp[101][101];
    int f(int i,int j,vector<vector<int>>& obstacleGrid,set<pair<int,int>> &st){
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1 && obstacleGrid[i][j]==0){
            return 1;
        }
        if(i>=obstacleGrid.size() || j>=obstacleGrid[0].size() || i<0 || j<0 || obstacleGrid[i][j]==1 || st.find({i,j})!=st.end()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        st.insert({i,j});
        int ans=f(i+1,j,obstacleGrid,st)+f(i,j+1,obstacleGrid,st);
        st.erase({i,j});
        return dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        set<pair<int,int>>st;
        memset(dp,-1,sizeof(dp));
        return f(0,0,obstacleGrid,st);
    }
};