class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        for(int i=0;i<m;i++)
        {
            auto it = upper_bound(grid[i].begin(),grid[i].end(),-1,
                             [](int a, int b) { return a >= b; }) - grid[i].begin();
            
            cout<<it<<" ";
            // if(grid[i][it]>=0)
            // ans--;
            ans+=n-it;
        }
        return ans;
    }
};