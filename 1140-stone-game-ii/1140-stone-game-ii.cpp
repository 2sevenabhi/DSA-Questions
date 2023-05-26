class Solution {
    vector<vector<int>> dp;
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        dp.resize(101, vector<int>(202)); 
        int sum=accumulate(piles.begin(),piles.end(),0);
        int diff=solve(piles,0,1);
        return (sum+diff)/2;
    }

    int solve(vector<int>& piles, int i, int m)
    {
        if(i>=piles.size())
        return 0;
        if(dp[i][m]!=0)
        return dp[i][m];
        int total=0,ans=INT_MIN;
        for(int j=0;j<2*m;j++)
        {
            if(i+j<piles.size())
            total+=piles[i+j];
            ans=max(ans,total-solve(piles,i+j+1, max(m,j+1)));
        }
        return dp[i][m]=ans;
    }
};