class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>>memo(n+1,vector<int>(k+1,0));
        function<int(int,int)>dp = [&](int i,int k){
            if(memo[i][k]>0)
            return memo[i][k];
            if(i==n ||k==0)
            return 0;
            int ans = dp(i+1,k),curr =0;
            for(int j=0;j<piles[i].size()&& j<k;j++){
                curr+=piles[i][j];
                ans = max(ans,dp(i+1,k-j-1)+curr);
            }
            memo[i][k] = ans;
            return ans;
        };
        return dp(0,k);
    }
};